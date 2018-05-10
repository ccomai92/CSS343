//
// Created by ccomai92 on 5/3/18.
//

#include "BitInputStream.h"

BitInputStream::BitInputStream(): input(), buffer(0), bufferSize(0) {}

BitInputStream::BitInputStream(std::string inputFile): 
				input(), buffer(0), bufferSize(0) {
	this->input.open(inputFile); 
	if (!this->input.is_open()) {
		std::cerr << "output file not open" << std::endl; 
	}
}

BitInputStream::~BitInputStream() {
	this->input.close(); 
}

unsigned int BitInputStream::getBit() {
	if (this->bufferSize == 0) {
		this->buffer = this->input.get();
	        this->bufferSize = 8; 	
	}
	unsigned int bit = this->buffer & (1 << (bufferSize - 1));	
	bit = bit >> (bufferSize - 1);
	this->bufferSize--;
	return bit;
}

unsigned char BitInputStream::getByte() {
	this->buffer = this->input.get(); 
	this->bufferSize = 0;
	std::bitset<8> testing(buffer);
	std::cerr << testing << std::endl; 
        return this->buffer;	
}



