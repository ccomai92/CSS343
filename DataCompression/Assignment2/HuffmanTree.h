//
// Created by ccomai92 on 4/29/18.
//

#ifndef DATACOMPRESSION_HUFFMANTREE_H
#define DATACOMPRESSION_HUFFMANTREE_H

#include <limits.h>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm> 
#include <functional>
#include "HuffmanNode.h"
#include "Heap.h"
#include "BitInputStream.h"

class HuffmanTree {
public:
    HuffmanTree();
    HuffmanTree(unsigned int count[]);
    HuffmanTree(BitInputStream& input); 
    ~HuffmanTree();
    
    void recordCodes(unsigned long long codes[], int sizes[]);
    void decode(BitInputStream& input, std::string outputFile, unsigned int numOfCharacters);

private:
    HuffmanNode* root;
    HuffmanNode* makeTree(
            Heap<HuffmanNode*,
                    std::vector<HuffmanNode*>,
                    CompareNode> priority);
    HuffmanNode* makeTree(
            HuffmanNode* current,
            unsigned long long code, int size,
            unsigned char character);
    void recordCodesHelper(HuffmanNode* current,
                           unsigned long long codes[], int sizes[],
                           unsigned long long code, int level);
    void decodeHelper(HuffmanNode* current,
                      BitInputStream& input, std::ofstream& output);
    void dump();
    void verify(unsigned long long codes[], int sizes[]);
    void dumpHelper(HuffmanNode* current, int level);
    void verifyHelper(HuffmanNode* current,
                      unsigned long long codes[], int sizes[],
                      unsigned long long code, int level);
    void clear();
    HuffmanNode* clearHelper(HuffmanNode* current);
};



#endif //DATACOMPRESSION_HUFFMANTREE_H
