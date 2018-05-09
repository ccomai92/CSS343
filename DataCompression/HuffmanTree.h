//
// Created by ccomai92 on 4/29/18.
//

#ifndef DATACOMPRESSION_HUFFMANTREE_H
#define DATACOMPRESSION_HUFFMANTREE_H

#include "Node.h"
#include "Heap.h"
#include "BitInputStream.h"
#include <limits.h>
#include <vector>
#include <iostream>
#include <string>
#include <fstream> 

class HuffmanTree {
public:
    HuffmanTree();
    HuffmanTree(unsigned int count[]);
    HuffmanTree(BitInputStream& input); 
    ~HuffmanTree();
    
    void recordCodes(unsigned long long codes[], int sizes[]);
    void decode(BitInputStream& input, std::string outputFile, unsigned int numOfCharacters);

    void dump();
    void verify(unsigned long long codes[], int sizes[]);

private:
    Node<unsigned char, unsigned int>* root;
    Node<unsigned char, unsigned int>* makeTree(
		    Heap<Node<unsigned char, unsigned int>*,
                    std::vector<Node<unsigned char, unsigned int>*>,
                    CompareNode<unsigned char, unsigned int>> priority);
    Node<unsigned char, unsigned int>* makeTree(
		    	Node<unsigned char, unsigned int>* current,
		    	unsigned long long code, int size,
		       	unsigned char character); 
    void recordCodesHelper(Node<unsigned char, unsigned int>* current,
                           unsigned long long codes[], int sizes[],
                           unsigned long long code, int level);
    void decodeHelper(Node<unsigned char, unsigned int>* current,
		      BitInputStream& input, std::ofstream& output);
    void dumpHelper(Node<unsigned char, unsigned int>* current, int level);
    void verifyHelper(Node<unsigned char, unsigned int>* current,
                      unsigned long long codes[], int sizes[],
                      unsigned long long code, int level);
    void clear();
    Node<unsigned char, unsigned int>* clearHelper(Node<unsigned char, unsigned int>* current);
};

#endif //DATACOMPRESSION_HUFFMANTREE_H
