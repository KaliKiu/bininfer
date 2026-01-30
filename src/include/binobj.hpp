#ifndef BINOBJ
#define BINOBJ

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <cassert>
#include <map>

#include "json.hpp"
#include "utils.hpp"
#include "analysiscontext.hpp"

class Binobj{
    const std::filesystem::path JSON_FILE_DIRECTORY_PATH = "JSON_FILES";
    private:
        const std::filesystem::path FILE_PATH;
        const std::vector<uint8_t> bin_file_vec;
        const std::size_t bin_file_size;

        const std::string json_file_id;
        const std::filesystem::path JSON_FILE_PATH;

    public:
        std::unique_ptr<AnalysisContext> acx;
        Binobj(const std::filesystem::path FILE_PATH_): 
            FILE_PATH(FILE_PATH_),
            bin_file_vec(buildBinaryVec(FILE_PATH_)),
            bin_file_size(buildBinaryFileSize(FILE_PATH_)),
            json_file_id(Utils::generateUUIDv4()),
            JSON_FILE_PATH(buildJsonFile()){

            acx = std::make_unique<AnalysisContext>();
        };
            std::vector<uint8_t> buildBinaryVec(std::filesystem::path FILE_PATH_){
                std::filesystem::create_directories(JSON_FILE_DIRECTORY_PATH);
                std::ifstream binfile(FILE_PATH_,std::ios::binary|std::ios::ate);
                if(!binfile.good()){
                    std::cout<<"Binobj Constructor: File input failed"<<std::endl;
                }
                std::streamsize file_size_ = binfile.tellg();
                assert(file_size_>=0);
                std::size_t _file_size_ = static_cast<std::size_t>(file_size_);

                binfile.seekg(0,std::ios::beg);
                std::vector<uint8_t> bin_file_vec_;
                bin_file_vec_.resize(_file_size_);

                //writes all data at once into *file[0]=file_.data(), vector then just interprets the 8bit blocks
                if(!binfile.read(reinterpret_cast<char*>(bin_file_vec_.data()),file_size_)){
                    throw std::runtime_error("BIN Failed to read");
                }
                return bin_file_vec_;
            }
            std::size_t buildBinaryFileSize(std::filesystem::path FILE_PATH_){
                std::filesystem::create_directories(JSON_FILE_DIRECTORY_PATH);
                std::ifstream binfile(FILE_PATH_,std::ios::binary|std::ios::ate);
                if(!binfile.good()){
                    std::cout<<"Binobj Constructor: File input failed"<<std::endl;
                }
                std::streamsize file_size_ = binfile.tellg();
                assert(file_size_>=0);
                return static_cast<std::size_t>(file_size_);
            }
            std::filesystem::path buildJsonFile(){
                std::filesystem::path JSON_FILE_PATH_ = JSON_FILE_DIRECTORY_PATH.string()+"/"+json_file_id+".json";
                std::ofstream file_json(JSON_FILE_PATH);
                if(!file_json)std::cout<<"JSON FILE: something went wrong";
                return JSON_FILE_PATH_;
            }

        /*~Binobj(){
            //destruct obj, (delete file etc.)
            if(!std::filesystem::remove(JSON_FILE_PATH)){
                std::cout<<"Binobj Destructor: JsonFilefailed";
            }

        };*/

        void writeToJson(){
            nlohmann::json json;
            std::ifstream file(JSON_FILE_PATH);
            if(!file.good())std::cerr<<"writeToJson";
            file>>json;
            file.close();
            json[Utils::Json::JSON_json_file_id] = json_file_id;
            json[Utils::Json::JSON_file_path] = FILE_PATH;
            json[Utils::Json::JSON_bin_file_size]=bin_file_size;
            json[Utils::Json::JSON_shannon_entropy]=acx->getShannonEntropy();
            json[Utils::Json::JSON_BlockEntropy] = acx->getBlockEntropy();
            
            std::ofstream out(JSON_FILE_PATH);
            if(!out.good())std::cerr<<"writeToJson2";

            out<<json.dump(4)<<std::endl;
            std::cout<<"worked?";
        }
        void hexdump(){
            int meow=0;
            for(auto& i :bin_file_vec){
                if(meow%16==0)std::cout<<std::endl;
                if(meow%2==0)std::cout<<" ";
                std::cout <<std::hex <<std::setw(2)<<std::setfill('0')<<static_cast<int>(i)<<" ";
                meow++;
            }
        }
        const std::vector<uint8_t>& getBinary()const{
            return bin_file_vec;
        }
        std::size_t getFile_Size(){
            return bin_file_size;
        }
        std::string getJson_File_Id(){
            return json_file_id;
        }


};

#endif
