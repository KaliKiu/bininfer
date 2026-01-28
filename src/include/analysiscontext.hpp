#ifndef ANALYSISCONTEXT
#define ANALYSISCONTEXT

#include <map>

class AnalysisContext{
    private:
        std::vector<std::pair<std::size_t,uint8_t>>  BinaryFrequency;
    public:
        AnalysisContext()=default;
        AnalysisContext& operator=(const AnalysisContext& other){
            if(BinaryFrequency!=other.BinaryFrequency){
                BinaryFrequency=other.BinaryFrequency;
            }
            return *this;
        }
        //getters/setters
        void setBinaryFrequency(std::vector<std::pair<std::size_t,uint8_t>> BinaryFrequency_){
            BinaryFrequency=BinaryFrequency_;
        }
        std::vector<std::pair<std::size_t,uint8_t>> getBinaryFrequency(){
            return BinaryFrequency;
        }

};

#endif