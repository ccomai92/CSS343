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

    void dump();

private:
    Node<unsigned char, unsigned int>* root;
    Node<unsigned char, unsigned int>* makeTree(
                    Heap<Node<unsigned char, unsigned int>*,
                    std::vector<Node<unsigned char, unsigned int>*>,
                    CompareNode<unsigned char, unsigned int>> priority);
    void dumpHelper(Node<unsigned char, unsigned int>* current, int level);

};


#endif //DATACOMPRESSION_HUFFMANTREE_H
