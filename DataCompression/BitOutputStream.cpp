//
// Created by ccomai92 on 5/3/18.
//

#include "BitOutputStream.h"

BitOutputStream::BitOutputStream(): output(), buffer(0), bufferIndex(0) {}

BitOutputStream::BitOutputStream(std::ostream &output):
                                output(output), buffer(0), bufferIndex(0) {}

BitOutputStream::~BitOutputStream() {
    flush();
}

int BitOutputStream::putBit(unsigned int bit) {
    this->buffer += bit << bufferIndex;
    this->bufferIndex++;
    if (this->bufferIndex == 8) {
        this->flush();
    }
    return 0;
}

int BitOutputStream::putByte(unsigned char byte) {
    return 0;
}

void BitOutputStream::flush() {
    output.write(this->buffer);
    this->buffer = 0;
    this->bufferIndex = 0;
}

void BitOutputStream::close() {

}
