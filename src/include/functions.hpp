#ifndef FUNCTIONS
#define FUNCTIONS

#include <map>
#include "binobj.hpp"

namespace Function{
//holds all methods from Stage 1-Stage 5
    void ByteFrequencyMap(Binobj binobj){
        std::map<uint8_t,std::size_t> map;
        const auto& bin = binobj.getBinary();

        for(auto& t : bin){
            //dosmth
        }

    }
};
#endif