//
// Created by ccomai92 on 4/29/18.
//

#include "HuffmanTree.h"


HuffmanTree::HuffmanTree(): root() {}

HuffmanTree::HuffmanTree(unsigned int count[]) {
    Heap<Node<unsigned char, unsigned int>*,
            std::vector<Node<unsigned char, unsigned int>*>,
            CompareNode<unsigned char, unsigned int>> priority;
    for (int i = 0; i < UCHAR_MAX + 1; i++) {
        if (count[i] > 0) {
            Node<unsigned char, unsigned int>* temp =
                    new Node<unsigned char, unsigned int>(i, count[i]);
            priority.Push(temp);
        }
    }
    priority.verify();
    this->root = makeTree(priority);
}

HuffmanTree::~HuffmanTree() {}

void HuffmanTree::recordCodes(unsigned long long* codes, int* sizes) {
    this->recordCodesHelper(this->root, codes, sizes, 0, 0);
}

Node<unsigned char, unsigned int>* HuffmanTree::makeTree(
                Heap<Node<unsigned char, unsigned int>*,
                std::vector<Node<unsigned char, unsigned int>*>,
                CompareNode<unsigned char, unsigned int>> priority) {
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

void HuffmanTree::recordCodesHelper(Node<unsigned char, unsigned int> *current,
                                    unsigned long long (*codes), int (*sizes),
                                    int (code), int level) {
    if (current != nullptr) {
        if (current->left() == nullptr && current->right() == nullptr) {
            unsigned char data = current->data();
            codes[data] = code;
            sizes[data] = level;
        } else {
            code = code << 1;
            recordCodesHelper(current->left(),
                              codes, sizes, code, level + 1);
            code = code + 1;
            recordCodesHelper(current->right(),
                              codes, sizes, code, level + 1);
        }
    }
}

