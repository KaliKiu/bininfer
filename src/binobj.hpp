#ifndef BINOBJ
#define BINOBJ

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>

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
            file_size=file_size_;
            binfile.seekg(0,std::ios::beg);
            std::vector<uint8_t> file_(file_size_);
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

        };


};
#endif