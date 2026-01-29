#ifndef FUNCTIONS
#define FUNCTIONS

#include <map>
#include <algorithm>
#include <cmath>
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
    void CalculateShannonEntropy(Binobj& binobj){
        //calc global entropy!
       std::size_t total_bytes=0;
        for(auto& t : binobj.acx->getBinaryFrequency()){
            total_bytes += t.first;
        }
        std::cout<<total_bytes<<std::endl;
        binobj.acx->setByteCountBinfile(total_bytes);
        double shannon_entropy=0;
        
        for(auto& t : binobj.acx->getBinaryFrequency()){
            double pi=t.first/static_cast<double>(binobj.acx->getByteCountBinfile());
            double contribution = pi*(std::log2(pi));
            shannon_entropy+=contribution;
        }
        shannon_entropy=(-1)*shannon_entropy;
        std::cout<<"shannon_entropy: "<<shannon_entropy<<std::endl;
        binobj.acx->setShannonEntropy(shannon_entropy);
    }

};
#endif