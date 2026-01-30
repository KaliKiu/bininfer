#include "include/binobj.hpp"
#include "include/functions.hpp"

int main(){

    Binobj mytestfile("meow");
    std::cout << mytestfile.getFile_Size();
    
    Function::ByteFrequencyMap(mytestfile);
    Function::CalculateShannonEntropy(mytestfile);
    Function::CalculateBlockEntropy(mytestfile);
    mytestfile.writeToJson();
    
    Function::printWhatsGoingOn(mytestfile);
}