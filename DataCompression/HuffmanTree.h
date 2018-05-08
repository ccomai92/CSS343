//
// Created by ccomai92 on 4/29/18.
//

#ifndef DATACOMPRESSION_HUFFMANTREE_H
#define DATACOMPRESSION_HUFFMANTREE_H

#include "Node.h"
#include "Heap.h"
#include <limits.h>
#include <vector>
#include <iostream>

class HuffmanTree {
public:
    HuffmanTree();
    HuffmanTree(unsigned int count[]);
    ~HuffmanTree();
    void recordCodes(unsigned long long* codes, int* sizes);
    void dump();

private:
    Node<unsigned char, unsigned int>* root;
    Node<unsigned char, unsigned int>* makeTree(
                    Heap<Node<unsigned char, unsigned int>*,
                    std::vector<Node<unsigned char, unsigned int>*>,
                    CompareNode<unsigned char, unsigned int>> priority);
    void recordCodesHelper(Node<unsigned char, unsigned int>* current,
            			unsigned long long (*codes), int (*sizes),
		    		    unsigned long long (code), int level);
    void dumpHelper(Node<unsigned char, unsigned int>* current, int level);
};


#endif //DATACOMPRESSION_HUFFMANTREE_H
