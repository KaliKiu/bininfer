#ifndef ANALYSISCONTEXT
#define ANALYSISCONTEXT

#include <map>

class AnalysisContext{
    private:
        std::map<uint8_t,std::size_t> BinaryFrequency;
    public:
        AnalysisContext()=default;
        AnalysisContext& operator=(const AnalysisContext& other){
            if(BinaryFrequency!=other.BinaryFrequency){
                BinaryFrequency=other.BinaryFrequency;
            }
            return *this;
        }
        //getters/setters
        void setBinaryFrequency(std::map<uint8_t,std::size_t> BinaryFrequency_){
            BinaryFrequency=BinaryFrequency_;
        }
        std::map<uint8_t,std::size_t> getBinaryFrequency(){
            return BinaryFrequency;
        }

};

#endif