#include <iostream> 
#include <fstream> 
#include <string> 
#include <cstdlib> // for EXIT_SUCCESS & EXIT_FAILURE
#include <limits.h> // for UCHAR_MAX 
#include "HuffmanTree.h"
#include "BitInputStream.h"

using namespace std; 

int main(int arc, char* argv[]) {
	// check if program has arguments required
	if (argc < 2) {
		cerr << "Require arguments!" << endl; 
		return EXIT_FAILURE; 
	}
	
	// take arguments passed into the program 
	string inputFile = argv[1]; 
	int nameSize = inputFile.length(); 
	string outputFile = inputFile.substr(0, nameSize - 4) + ".puff"; 
	
	// open BitInputStream 
	BitInputStream input(inputFile); 

	unsigned long long codes[UCHAR_MAX + 1]; 
	int sizes[UCHAR_MAX + 1]; 

	// read Coded Symbols in the header of inputFile 
	for (int i = 0; i < UCHAR_MAX + 1; i++) {
		
	}

	HuffmanTree tree(codes, sizes); 

	return EXIT_SUCCESS; 
}
