#include "include/binobj.hpp"


int main(){
    Binobj mytestfile("test.bin");
    std::cout << mytestfile.getFile_Size();
    mytestfile.hexdump();

    std::cout<<"well worked";
}