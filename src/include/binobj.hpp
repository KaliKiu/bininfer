#ifndef BINOBJ
#define BINOBJ

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <cassert>

#include "utils.hpp"

class Binobj{
    const std::filesystem::path JSON_FILE_DIRECTORY_PATH = "JSON_FILES";
    private:
        const std::filesystem::path FILE_PATH;
        std::vector<uint8_t> file;
        std::size_t file_size;

        std::string json_file_id;
        std::filesystem::path JSON_FILE_PATH;

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
            if(!binfile.read(reinterpret_cast<char*>(file_.data()),file_size_)){
                throw std::runtime_error("BIN Failed to read");
            }
            file=file_;

            json_file_id = Utils::generateUUIDv4();
            JSON_FILE_PATH = JSON_FILE_DIRECTORY_PATH.string()+"/"+json_file_id+".json";
            std::ofstream file_json(JSON_FILE_PATH);
            if(!file_json)
                std::cout<<"JSON FILE: something went wrong";
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
                std::cout <<std::hex <<std::setw(2)<<std::setfill('0')<<static_cast<int>(i)<<" ";
                meow++;
            }
        }
        //getters/setters
        std::size_t getFile_Size(){
            return file_size;
        }


};
#endif

/*std::vector<char> file_(file_size);
            for(int i{0};i<static_cast<int>(file_size/16);i++){
                char meow =0;
                binfile.seekg(i*16,std::ios::beg);
                if(!binfile.read(reinterpret_cast<char*>(meow),16)){
                    throw std::runtime_error("BIN Failed to read");
                }
            file_.push_back(meow);
            }*/