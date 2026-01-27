#include "include/binobj.hpp"
#include "include/functions.hpp"

int main(){
    Binobj mytestfile("test.bin");
    std::cout << mytestfile.getFile_Size();
    mytestfile.hexdump();
    
    Function::ByteFrequencyMap(mytestfile);

    std::cout<<"well worked";
}