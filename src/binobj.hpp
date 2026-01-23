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

    public:
        Binobj(std::string FILE_PATH_): FILE_PATH(FILE_PATH_){
            std::ifstream binfile(FILE_PATH,std::ios::binary|std::ios::ate);
            if(!binfile.good()){
                std::cout<<"Binobj Constructor: File input failed"<<std::endl;
            }
            
        }

};
#endif