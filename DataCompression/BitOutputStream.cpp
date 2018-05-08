//
// Created by ccomai92 on 5/3/18.
//

#include "BitOutputStream.h"

BitOutputStream::BitOutputStream() : output(), buffer(0), bufferSize(0) {}

BitOutputStream::BitOutputStream(std::string outputFile) :
        output(), buffer(0), bufferSize(0) {
    this->output.open(outputFile);
    if (!this->output.is_open()) {
        std::cerr << "output file not open" << std::endl;
    }
}

BitOutputStream::~BitOutputStream() {
    flush();
    this->output.close();
}

int BitOutputStream::putBit(unsigned int bit) {
    if (bit < 0 || bit > 1) {
        return 0;
    }

    this->buffer = (this->buffer << 1) + bit;
    this->bufferSize++;

    if (this->bufferSize == 8) {
        this->flush();
    }
    return 1;
}

int BitOutputStream::putByte(unsigned char byte) {
    this->buffer = byte;
    this->bufferSize = 8;
    this->flush();
    return 0;
}

void BitOutputStream::flush() {
    if (this->bufferSize > 1) {
        this->buffer = this->buffer << (8 - this->bufferSize);
        std::bitset<8> dump(this->buffer);
        std::cerr << dump << std::endl;
        output.put(this->buffer);
        this->buffer = 0;
        this->bufferSize = 0;
    }
}
