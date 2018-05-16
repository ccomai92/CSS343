//
// Created by ccomai92 on 4/29/18.
//

#ifndef DATACOMPRESSION_HEAP_H
#define DATACOMPRESSION_HEAP_H

#include <vector>
#include <iostream>
#include <algorithm> // reference: cplusplus.com

template<class T,
        class Container = std::vector<T>,
        typename Compare = std::less<T>>
class Heap {
public:
    Heap();
    ~Heap();

    void Push(T item);
    T Pop();
    bool isEmpty();
    int size();

    bool verify();

private:
    Container list;
    Compare compare;
    void swap(int index1, int index2);
    void print();
};

template<class T,
        class Container,
        class Compare>
Heap<T, Container, Compare>::Heap() : list(), compare() {
    this->list.push_back(T{});
}

template<class T, class Container, class Compare>
Heap<T, Container, Compare>::~Heap() {}


template<class T, class Container, class Compare>
bool Heap<T, Container, Compare>::isEmpty() {
    return this->list.size() < 2;
}

template<class T, class Container, class Compare>
void Heap<T, Container, Compare>::Push(T item) {
    this->list.push_back(item);
    int index = this->list.size() - 1;
    bool done = false;
    while (index > 1 && !done) {
        int parentIndex = index / 2;
        T child = this->list[index];
        T parent = this->list[parentIndex];
        if (this->compare(child, parent)) {
            this->swap(index, parentIndex);
        }
        else {
            done = true;
        }
        index = parentIndex;
    }
}


template<class T, class Container, class Compare>
void Heap<T, Container, Compare>::swap(int index1, int index2) {
    T temp = this->list[index1];
    this->list[index1] = this->list[index2];
    this->list[index2] = temp;

}

template<class T, class Container, class Compare>
T Heap<T, Container, Compare>::Pop() {
    T result = this->list[1];
    int size = this->list.size();
    this->list[1] = this->list[size - 1];
    this->list.pop_back();
    size = this->list.size();
    int index = 1;
    bool done = false;
    while (index < (size / 2) && !done) {
        int leftIndex = index * 2;
        int rightIndex = (index * 2) + 1;
        T parent = this->list[index];
        T left = this->list[leftIndex];
        T right = this->list[rightIndex];
        if (this->compare(left, right)) {
            if (this->compare(left, parent)) {
                this->swap(leftIndex, index);
                index = leftIndex;
            }
            else {
                done = true;
            }
        }
        else {
            if (this->compare(right, parent)) {
                this->swap(rightIndex, index);
                index = rightIndex;
            }
            else {
                done = true;
            }
        }
    }

    if (size != 1 && size % 2 == 1) {
        int parentIndex = size / 2;
        int leftIndex = size - 1;
        T parent = this->list[parentIndex];
        T left = this->list[leftIndex];
        if (this->compare(left, parent)) {
            this->swap(parentIndex, leftIndex);
        }
    }

    return result;
}

template<class T, class Container, class Compare>
bool Heap<T, Container, Compare>::verify() {
    int size = this->list.size();
    this->print();
    for (int i = 1; i < size / 2; i++) {
        T parent = this->list[i];
        T left = this->list[i * 2];
        T right = this->list[(i * 2) + 1];
        if (this->compare(left, parent) || this->compare(right, parent))
        {
            std::cerr << "verification code: False" << std::endl;
            return false;
        }
    }
    if (size % 2 == 1) {
        T parent = this->list[size / 2];
        T left = this->list[size - 1];
        if (this->compare(left, parent)) {
            std::cerr << "verification code: False" << std::endl;
        }
        return false;
    }

    std::cerr << "verification code: True" << std::endl;
    return true;

}

template<class T, class Container, class Compare>
void Heap<T, Container, Compare>::print() {
    int size = this->list.size();
    std::cerr << "[";
    for (int i = 1; i < size; i++) {
        std::cerr << *this->list[i];
    }
    std::cerr << "]" << std::endl;

}

template<class T, class Container, class Compare>
int Heap<T, Container, Compare>::size() {
    return this->list.size() - 1;
}

#endif //DATACOMPRESSION_HEAP_H
