#ifndef FUNCTIONS
#define FUNCTIONS

#include <map>
#include <algorithm>
#include "binobj.hpp"

namespace Function{
//holds all methods from Stage 1-Stage 5
    void ByteFrequencyMap(Binobj& binobj){
        std::map<uint8_t,std::size_t> map;
        std::vector<std::pair<std::size_t,uint8_t>> result;
        const auto& bin = binobj.getBinary();

        for(auto& t : bin){
            map[t]++;
        }
        for(auto& b : map){
            result.push_back({b.second,b.first}); //my beloved initializer_list meow
        }
        std::sort(result.begin(),result.end());
        for(auto& c : result){
            std::cout <<std::dec <<static_cast<int>(c.first)<<std::hex <<": "<<static_cast<int>(c.second)<<std::endl;;
        }
        std::cout<<std::endl<<std::dec<<result.size()<<" bytes";
        binobj.acx->setBinaryFrequency(result);
    }
};
#endif