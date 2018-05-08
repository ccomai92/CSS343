//
// A class for writing bits (and chars and ints) to an ostream
//

#ifndef DATACOMPRESSION_BITOUTPUTSTREAM_H
#define DATACOMPRESSION_BITOUTPUTSTREAM_H
#include <iostream>
#include <fstream>
#include <bitset>
#include <string>

class BitOutputStream {
public:
    BitOutputStream();
    BitOutputStream(std::string outputFile);
    ~BitOutputStream();

    int putBit(unsigned int bit);
    int putByte(unsigned char byte);
    void flush();

private:
    std::ofstream output;
    unsigned char buffer; // the buffer of bits
    int bufferSize;       // the bit buffer index

};


#endif //DATACOMPRESSION_BITOUTPUTSTREAM_H
