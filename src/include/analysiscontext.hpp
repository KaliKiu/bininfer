#ifndef ANALYSISCONTEXT
#define ANALYSISCONTEXT

#include <map>

class AnalysisContext{
    private:
        std::vector<std::pair<std::size_t,uint8_t>>  BinaryFrequency;
        std::size_t byte_count_binfile;
        double shannon_entropy;
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
        std::vector<std::pair<std::size_t,uint8_t>>& getBinaryFrequency(){
            return BinaryFrequency;
        }
        void setByteCountBinfile(std::size_t byte_count_binfile_){
            byte_count_binfile = byte_count_binfile_;
        }
        std::size_t getByteCountBinfile()const{
            return byte_count_binfile;
        }
        void setShannonEntropy(double shannon_entropy_){
            shannon_entropy=shannon_entropy_;
        }
        double getShannonEntropy()const{
            return shannon_entropy;
        }

};

#endif