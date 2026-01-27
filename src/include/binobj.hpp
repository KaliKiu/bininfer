#ifndef BINOBJ
#define BINOBJ

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <cassert>
#include <map>

#include "utils.hpp"
#include "functions.hpp"

class Binobj{
    const std::filesystem::path JSON_FILE_DIRECTORY_PATH = "JSON_FILES";
    private:
        const std::filesystem::path FILE_PATH;
        std::vector<uint8_t> file;
        std::size_t file_size;

        std::string json_file_id;
        std::filesystem::path JSON_FILE_PATH;
        std::unique_ptr<AnalysisContext> acx;

    public:
        Binobj(const std::filesystem::path FILE_PATH_): FILE_PATH(FILE_PATH_){

            std::filesystem::create_directories(JSON_FILE_DIRECTORY_PATH);
            std::ifstream binfile(FILE_PATH,std::ios::binary|std::ios::ate);
            if(!binfile.good()){
                std::cout<<"Binobj Constructor: File input failed"<<std::endl;
            }
            std::streamsize file_size_ = binfile.tellg();
            assert(file_size_>=0);
            file_size = static_cast<std::size_t>(file_size_);

            binfile.seekg(0,std::ios::beg);
            std::vector<uint8_t> file_;
            file_.resize(file_size);

            //writes all data at once into *file[0]=file_.data(), vector then just interprets the 8bit blocks
            if(!binfile.read(reinterpret_cast<char*>(file_.data()),file_size_)){
                throw std::runtime_error("BIN Failed to read");
            }
            file=file_;

            json_file_id = Utils::generateUUIDv4();
            JSON_FILE_PATH = JSON_FILE_DIRECTORY_PATH.string()+"/"+json_file_id+".json";
            std::ofstream file_json(JSON_FILE_PATH);
            if(!file_json)std::cout<<"JSON FILE: something went wrong";

            acx = std::make_unique<AnalysisContext>();
        };
        ~Binobj(){
            //destruct obj, (delete file etc.)
            if(!std::filesystem::remove(JSON_FILE_PATH)){
                std::cout<<"Binobj Destructor: JsonFilefailed";
            }
        };

        void hexdump(){
            int meow=0;
            for(auto& i :file){
                if(meow%16==0)std::cout<<std::endl;
                if(meow%2==0)std::cout<<" ";
                std::cout <<std::hex <<std::setw(2)<<std::setfill('0')<<static_cast<int>(i)<<" ";
                meow++;
            }
        }
        std::size_t getFile_Size(){
            return file_size;
        }
        std::string getJson_File_Id(){
            return json_file_id;
        }


};
//Result holder + JsonFile writer
class AnalysisContext{
    private:
        std::map<uint8_t,std::size_t> BinaryFrequency;
    public:
    AnalysisContext()=default;
    AnalysisContext& operator=(const AnalysisContext& other){
        if(this!=&other){
            BinaryFrequency=other.BinaryFrequency;
        }
        return *this;
        }
};
#endif
