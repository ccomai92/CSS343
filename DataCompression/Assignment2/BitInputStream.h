//
// Created by ccomai92 on 5/3/18.
//

#ifndef DATACOMPRESSION_BITINPUTSTREAM_H
#define DATACOMPRESSION_BITINPUTSTREAM_H

#include <iostream> 
#include <fstream> 
#include <bitset> 
#include <string> 

class BitInputStream {
public:
    BitInputStream();
    BitInputStream(std::string inputFile); 
    ~BitInputStream();

    unsigned int getBit(); 
    unsigned char getByte();

private:
    std::ifstream input; 
    unsigned char buffer;  
    int bufferSize; 	  
};


#endif //DATACOMPRESSION_BITINPUTSTREAM_H
