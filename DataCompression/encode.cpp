#include <string>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <cstdlib>
#include <bitset>
#include <math.h>
#include "HuffmanTree.h"
#include "BitOutputStream.h"

using namespace std;

void dump(unsigned int frequency[]);
void verify(string inputFile, unsigned int frequency[]);
void dump(unsigned long long codes[], int sizes[]);
void writeHeader(BitOutputStream& output,
				 unsigned long long codes[],
				 int sizes[], unsigned int count);
void write(BitOutputStream& output, unsigned long long codes[],
		   int sizes[], string inputFile);

int main(int argc, char* argv[]) {
	// check if program has arguments required
	if (argc < 2) {
		cerr << "Require arguments!" << endl;
		return EXIT_FAILURE;
	}

	// take arguments passed into the program
	string inputFile = argv[1];
	int nameSize = inputFile.length();
	string outputFile = inputFile.substr(0, nameSize - 4) + ".huff";

	// open input file and read characters
	// make frequency table.
	unsigned int count = 0; 
	ifstream input;
	input.open(inputFile);
	unsigned int frequency[UCHAR_MAX + 1] = { 0 };
	if (input.is_open()) {
		char ch;
		while (!input.eof()) {
			input.get(ch);
			count++; 
			unsigned char character =
					static_cast<unsigned char>(ch);
			frequency[character]++;
		}
	}
	else {
		return EXIT_FAILURE;
	}
	input.close();

	// Testing inputs are proper
	dump(frequency);
	verify(inputFile, frequency);


	// build huffman tree to make codes for compression
	HuffmanTree tree(frequency);
	tree.dump();
	unsigned long long codes[UCHAR_MAX + 1] = { 0 };
	int sizes[UCHAR_MAX + 1] = { 0 };
	tree.recordCodes(codes, sizes); // should print out bits to cerr
	dump(codes, sizes);
	tree.verify(codes, sizes);
	// open output file
	BitOutputStream output(outputFile);

	// write header to the output file
	writeHeader(output, codes, sizes, count);

	// write text
	write(output, codes, sizes, inputFile);

	return EXIT_SUCCESS;
}

void dump(unsigned int frequency[]) {
	unsigned int maxNum = 0;
	cerr << "Character\tHex\tprintable\tcount" << endl;
	for (int i = 0; i < UCHAR_MAX + 1; i++) {
		char character = i;
		maxNum = max(frequency[i], maxNum);
		cerr << character << "\t\t" << hex
			 << (unsigned int)i << "\t"
			 << (bool)isprint(i) << "\t\t"
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

void verify(string inputFile, unsigned int frequency[]) {
	ifstream input;
	input.open(inputFile);
	if (input.is_open()) {
		char ch;
		while (!input.eof()) {
			input.get(ch);
			unsigned char character = static_cast<unsigned char>(ch);
			frequency[character]--;
		}
	}
	input.close();
	for (int i = 0; i < UCHAR_MAX + 1; i++) {
		unsigned int fre = frequency[i];
		cerr << (char)i << ": " << fre << " ";
		if (fre != 0) {
			cerr << "FALSE" << endl;
		}
		else {
			cerr << "TRUE" << endl;
		}
	}
	input.open(inputFile);
	if (input.is_open()) {
		char ch;
		while (!input.eof()) {
			input.get(ch);
			unsigned char character = static_cast<unsigned char>(ch);
			frequency[character]++;
		}
	}
	input.close();
}

void dump(unsigned long long codes[], int sizes[]) {
	for (int i = 0; i < UCHAR_MAX + 1; i++) {
		int size = sizes[i];
		if (size > 0) {
			unsigned long long code = codes[i];
			bitset<64> bitCode(code);
			cerr << (char)i << ": "
				 << size << " " << bitCode << endl;
		}
	}
}

void writeHeader(BitOutputStream& output, unsigned long long codes[], 
		 int sizes[], unsigned int count) {
	for (int i = 0; i < UCHAR_MAX + 1; i++) {
		unsigned long long code = codes[i];
		int size = sizes[i];
		unsigned char codeSize = static_cast<unsigned char>(size);
		cerr << (char)i << endl;
		output.putByte(codeSize);
		if (size > 0) {
			for (int i = 0; i < size; i++) {
				int shifting = size - 1 - i;
				unsigned long long temp = code & (1 << shifting);
				unsigned int bit = (temp >> shifting) & 1;
				output.putBit(bit);
			}
			output.flush();
		}
	}
	cerr << "count symbols = " << count << endl;
	for (int i = 0; i < 4; i++) {
		unsigned char temp = static_cast<unsigned char>(count);
		output.putByte(temp);
		count = count >> 8;

	}
}

void write(BitOutputStream& output, unsigned long long codes[],
		   int sizes[], string inputFile) {
	cerr << "encoding txt file: " << endl;
	ifstream input;
	input.open(inputFile);
	if (input.is_open()) {
		char ch;
		while (!input.eof()) {
			input.get(ch);
			unsigned char character =
					static_cast<unsigned char>(ch);
			unsigned long long code = codes[character];
			int size = sizes[character];
			bitset<64> dump(code);
			cerr << character << " "
				 << dump << " " << size << endl;
			for (int i = 0; i < size; i++) {
				int shifting = size - 1 - i;
				unsigned long long temp = code & (1 << shifting);
				unsigned int bit = (temp >> shifting) & 1;
				output.putBit(bit);
			}
		}
		output.flush();
	}
	input.close();
}
