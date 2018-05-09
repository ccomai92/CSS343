#include <iostream> 
#include <fstream> 
#include <string> 
#include <cstdlib> // for EXIT_SUCCESS & EXIT_FAILURE
#include <limits.h> // for UCHAR_MAX 
#include "HuffmanTree.h"
#include "BitInputStream.h"

using namespace std; 

unsigned int readHeader(BitInputStream& input);

int main(int argc, char* argv[]) {
	// check if program has arguments required
	if (argc < 2) {
		cerr << "Require arguments!" << endl; 
		return EXIT_FAILURE; 
	}
	
	// take arguments passed into the program 
	string inputFile = argv[1]; 
	int nameSize = inputFile.length();	
	string expectedExtension = "huff"; 
	string actualExtension = inputFile.substr(nameSize - 4); 
	if (expectedExtension.compare(actualExtension) != 0) {
		cerr << "InputFile must be .huff" << endl; 
		return EXIT_FAILURE;
	}
	string outputFile = inputFile.substr(0, nameSize - 4) + "puff"; 
	
	// open BitInputStream 
	BitInputStream input(inputFile); 	
	
	// Build HuffmanTree based on the header information. 
	HuffmanTree tree(input); 

	// Read number of Characters
	unsigned int numOfCharacters = readHeader(input);
	std::cerr << "num of characters" << numOfCharacters << std::endl;
	// Read .huff file and print it out to .puff file. 
	tree.decode(input, outputFile, numOfCharacters); 	

	return EXIT_SUCCESS; 
}

unsigned int readHeader(BitInputStream& input) {
	unsigned int numOfCharacters = 0; 
	for (int i = 0; i < 4; i++) {
		numOfCharacters += input.getByte() << (i * 8); 
	}
	return numOfCharacters; 
}
