#ifndef UTILS
#define UTILS

#include <string>
#include <random>
#include <sstream>
#include <iomanip>
#include <cctype>



namespace Utils{
    namespace Json{
        inline constexpr const char* JSON_json_file_id = "json_file_id";
        inline constexpr const char* JSON_file_path = "FILE_PATH";
        inline constexpr const char* JSON_bin_file_size = "bin_file_size";
        inline constexpr const char* JSON_shannon_entropy= "shannon_entropy";
        inline constexpr const char* JSON_BlockEntropy = "block_entropy";
    }
    std::string generateUUIDv4(){
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<int> dis(0,255);

        uint8_t bytes[16];
        for(auto& b : bytes) b=static_cast<uint8_t>(dis(gen));

        bytes[6]= (bytes[6]& 0x0F)|0x40;

        bytes[8]= (bytes[8]& 0x3F)|0x80;

        std::stringstream ss;
        ss<<std::hex<<std::setfill('0');
        for(int i{0};i<16;++i){
            ss<<std::setw(2)<<static_cast<int>(bytes[i]);
            if(i==3||i==5||i==7||i==9)
                ss<<'-';
        }
        return ss.str();
    } 
    
}

#endif