//
// A class for writing bits (and chars and ints) to an ostream
//

#ifndef DATACOMPRESSION_BITOUTPUTSTREAM_H
#define DATACOMPRESSION_BITOUTPUTSTREAM_H
#include <iostream>
#include <fstream>
#include <bitset>

class BitOutputStream {
public:
    BitOutputStream();
    BitOutputStream(std::ostream& output);
    ~BitOutputStream();

    int putBit(unsigned int bit);
    int putByte(unsigned char byte);
    void flush();
    void close();

private:
    std::ostream& output;
    unsigned int buffer; // the buffer of bits
    int bufferIndex;       // the bit buffer index

};


#endif //DATACOMPRESSION_BITOUTPUTSTREAM_H
