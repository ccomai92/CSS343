//
// Created by ccomai92 on 4/29/18.
//

#include "HuffmanTree.h"


HuffmanTree::HuffmanTree() {}


HuffmanTree::HuffmanTree(unsigned int count[]) {
    Heap<unsigned char, unsigned int> priority;
    for (int i = 0; i < UCHAR_MAX + 1; i++) {
        if (count[i] > 0) {
            priority.Push(i, count[i]);
        }
    }
    priority.verify();
    this->root = makeTree(priority);
}

HuffmanTree::~HuffmanTree() {}

Node<unsigned char, unsigned int>* HuffmanTree::makeTree(
                                Heap<unsigned char, unsigned int> priority) {
    while (priority.size() > 1) {
        Node<unsigned char, unsigned int>* first = priority.Pop();
        Node<unsigned char, unsigned int>* second = priority.Pop();
        unsigned int frequencySum = first->priority() + second->priority();
        Node<unsigned char, unsigned int>* branch =
                new Node<unsigned char, unsigned int> (frequencySum, first, second);
        priority.Push(branch);
        priority.verify();
    }
    return priority.Pop();
}

void HuffmanTree::dump() {
    this->dumpHelper(this->root, 0);
}

void HuffmanTree::dumpHelper(Node<unsigned char, unsigned int>* current, int level) {
    if (current != nullptr) {
        this->dumpHelper(current->right(), level + 1);
        for (int i = 0; i < level; i++) {
            std::cerr << "\t";
        }
        std::cerr << *current << std::endl;
        this->dumpHelper(current->left(), level + 1);
    }
}


