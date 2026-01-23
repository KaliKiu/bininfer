#ifndef BINOBJ
#define BINOBJ

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Binobj{
    private:
        std::string FILE_PATH;
        std::vector<uint8_t> file;
        std::size_t file_size;

    public:
        Binobj(std::string FILE_PATH_): FILE_PATH(FILE_PATH_){
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
        }

};
#endif