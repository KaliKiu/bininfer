#ifndef BINOBJ
#define BINOBJ

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>

class Binobj{
    const std::string JSON_FILE_DIRECTORY_PATH = "JSON_FILES";
    private:
        std::string FILE_PATH;
        std::vector<uint8_t> file;
        std::size_t file_size;

        uint32_t json_file_id;
        std::string JSON_FILE_PATH;

    public:
        std::size_t threadCount(){
        namespace fs = std::filesystem;
        fs::path folder = "JSON_FILES";
        std::size_t count = 0;

        for (const auto& entry : fs::directory_iterator(folder)) {
            ++count;
        }
        return count;
    }
        Binobj(std::string FILE_PATH_): FILE_PATH(FILE_PATH_){
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
                throw std::runtime_error("Failed to read");
            }
            file=file_;
            json_file_id =
            std::ofstream file_json();
        }

};
#endif