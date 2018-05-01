//
// Created by ccomai92 on 4/29/18.
//

#ifndef DATACOMPRESSION_HEAP_H
#define DATACOMPRESSION_HEAP_H

#include <vector>
#include <iostream>
#include <algorithm>
#include "Node.h"

template<class Data, class Priority>
class Heap {
public:
    Heap();
    ~Heap();

    void Push(Data data, Priority priority);
    void Push(Node<Data, Priority>* input);
    Node<Data, Priority>* Pop();
    bool isEmpty();
    int size();

    bool verify();

private:
    std::vector<Node<Data, Priority>*> list;
    void swap(int index1, int index2);
    void print();
};

template<class Data, class Priority>
Heap<Data, Priority>::Heap(): list() {
    Node<Data, Priority>* temp{};
    this->list.push_back(temp);
}

template<class Data, class Priority>
Heap<Data, Priority>::~Heap() {}


template<class Data, class Priority>
bool Heap<Data, Priority>::isEmpty() {
    return this->list.size() < 2;
}

template<class Data, class Priority>
void Heap<Data, Priority>::Push(Data data, Priority priority) {
    Node<Data, Priority>* temp = new Node<Data, Priority>(data, priority);
    this->Push(temp);
}

template<class Data, class Priority>
void Heap<Data, Priority>::Push(Node<Data, Priority>* input) {
    this->list.push_back(input);
    int index = this->list.size() - 1;
    bool done = false;
    while (index > 1 && !done) {
        int parentIndex = index / 2;
        Node<Data, Priority>* child = this->list[index];
        Node<Data, Priority>* parent = this->list[parentIndex];
        if (*(child) < *(parent)) {
            this->swap(index, parentIndex);
        } else {
            done = true;
        }
        index = parentIndex;
    }
}


template<class Data, class Priority>
void Heap<Data, Priority>::swap(int index1, int index2) {
    Node<Data, Priority>* temp = this->list[index1];
    this->list[index1] = this->list[index2];
    this->list[index2] = temp;

}

template<class Data, class Priority>
Node<Data, Priority>* Heap<Data, Priority>::Pop() {
    Node<Data, Priority>* result = this->list[1];
    int size = this->list.size();
    this->list[1] =  this->list[size - 1];
    this->list.pop_back();
    size = this->list.size();
    int index = 1;
    bool done = false;
    while (index < (size / 2) && !done) {
        int leftIndex = index * 2;
        int rightIndex = (index * 2) + 1;
        Node<Data, Priority>* parent = this->list[index];
        Node<Data, Priority>* left = this->list[leftIndex];
        Node<Data, Priority>* right = this->list[rightIndex];
        if (*left <= *right) {
            if (*(parent) > *(left)) {
                this->swap(leftIndex, index);
                index = leftIndex;
            } else {
                done = true;
            }
        } else  {
            if ((*parent) > *(right)) {
                this->swap(rightIndex, index);
                index = rightIndex;
            } else {
                done = true;
            }
        }
    }

    if (size != 1 && size % 2 == 1) {
        int parentIndex = size / 2;
        int leftIndex = size - 1;
        Node<Data, Priority>* parent = this->list[parentIndex];
        Node<Data, Priority>* left = this->list[leftIndex];
        if (*(parent) > *(left)) {
            this->swap(parentIndex, leftIndex);
        }
    }

    return result;
}

template<class Data, class Priority>
bool Heap<Data, Priority>::verify() {
    int size = this->list.size();
    this->print();
    for (int i = 1; i < size / 2; i++) {
        Node<Data, Priority>* parent = this->list[i];
        Node<Data, Priority>* left = this->list[i * 2];
        Node<Data, Priority>* right = this->list[(i * 2) + 1];
        if (*(parent) > *(left) || *(parent) > *(right))
        {
            std::cerr << "verification code: False" << std::endl;
            return false;
        }
    }
    if (size % 2 == 1) {
        Node<Data, Priority>* parent = this->list[size / 2];
        Node<Data, Priority>* left = this->list[size - 1];
        if (*(parent) > *(left)) {
            std::cerr << "verification code: False" << std::endl;
        }
        return false;
    }

    std::cerr << "verification code: True" << std::endl;
    return true;

}

template<class Data, class Priority>
void Heap<Data, Priority>::print() {
    int size = this->list.size();
    std::cerr << "[" << std::endl;
    for (int i = 1; i < size; i++) {
        std::cerr << *(this->list[i]);
    }
    std::cerr << "]" << std::endl;

}

template<class Data, class Priority>
int Heap<Data, Priority>::size() {
    return this->list.size() - 1;
}

#endif //DATACOMPRESSION_HEAP_H
