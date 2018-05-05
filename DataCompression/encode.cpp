#include <string> 
#include <fstream> 
#include <iostream> 
#include <limits.h>
#include <cstdlib>
#include "HuffmanTree.h"
#include "BitOutputStream.h" 

using namespace std; 

void dump(unsigned int frequency[]); 
void writeHeader(BitOutputStream output, unsigned long long codes[]);

int main(int argc, char* argv[]) {
	// check if program has arguments required
	if (argc < 2) {
		cerr << "Require arguments!" << endl; 
		return EXIT_FAILURE;
	}
	
	// take arguments passed into the program 
	string inputFile = argv[1]; 
	string outputFile = argv[2];

	// open input file and read characters 
	// make frequency table. 
	ifstream input; 
	input.open(inputFile); 
	unsigned int frequency[UCHAR_MAX + 1] = {0}; 
	if (input.is_open()) {
		unsigned char character; 
		while (!input.eof()) {
			input >> character; 
			frequency[character]++; 
		}
	} else {
		return EXIT_FAILURE; 
	}
	input.close(); 
	
	// Testing inputs are proper 
	dump(frequency); 


	// build huffman tree to make codes for compression 
	HuffmanTree tree(frequency); 
	tree.dump(); 
	unsigned long long codes[UCHAR_MAX + 1];
	int size[UCHAR_MAX + 1]; 
	tree.makeCode(code, size); // should print out bits to cerr 
	
	// open output file  
	BitOutputStream output(outputFile); 

	// write coded table to the output file 
	

	output.close(); 


	return EXIT_SUCCESS; 
}

void dump(unsigned int frequency[]) {
	unsigned int maxNum = 0; 
	cerr << "Character\tHex\tprintable\tcount" << endl;
	for (int i = 0; i < UCHAR_MAX + 1; i++) {
		char character = i;
		maxNum = max(frequency[i], maxNum); 
		cerr << character << "\t\t" << hex 
			<< (unsigned int) i << "\t" 
			<< (bool) isprint(i) << "\t\t" 
			<< dec << frequency[i] << endl; 
	}

	for (int i = 0; i < UCHAR_MAX + 1; i++) {
		char character = i; 
		cerr << character << ": "; 
		unsigned int number = 50 * frequency[i] / maxNum; 
		for (int j = 0; j < number; j++) {
			cerr << "*"; 
		}
		cerr << endl; 
	}
}

void writeHeader(BitOutputStream output, unsigned long long codes[]) {
	for (int i = 0; i < UCHAR_MAX + 1; i++) {
		character = i; 
		unsigned long long code = codes[i]; 
		
	} 
}
