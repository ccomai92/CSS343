/* Reference:  
 *  https://courses.washington.edu/css343/bernstein/2018-q2/assignment-03/priority.h 
 *  "priority.h" is modified by Kris Kwon.  
 */ 

#ifndef SCHEDULING_PRIORITY_H
#define SCHEDULING_PRIORITY_H

#include <vector> 

template<class T, class Compare> 
class PriorityQueue {
public: 
    PriorityQueue(Compare compare);
    ~PriorityQueue(); 

    void push(T* input); 
    void reduce(T* target); 
    T* pop(); 
    bool isEmpty() {}
private:
    PriorityQueue(): {}

    Compare _compare;
    std::vector<T*> _list;

    void swap(int index1, int index2); 
    void shift_up(int n); 
    void shift_down(int n);  
}; 

template<class T, class Compare> 
PriorityQueue<T, Compare>::PriorityQueue(Compare compare):
 _compare(compare), _list() {
    this->_list[0] = T*{}; 
}

template<class T, class Compare> 
PriorityQueue<T, Compare>::~PriorityQueue() {}

template<class T, class Compare> 
void PriorityQueue<T, Compare>::swap(int index1, int index2) {
    T* temp = this->_list[index1]; 
    this->_list[index1] = this->_list[index2]; 
    this->_list[index2] = temp;  
    this->_list[index1]->setIndex(index1); 
    this->_list[index2]->setIndex(index2); 
} 

template<class T, class Compare>
void PriorityQueue<T, Compare>::shift_up(int index) {
    bool done = false; 
    while (index > 1 && !done) {
        int parentIndex = index / 2; 
        T* child = this->_list[index]; 
        T* parent = this->_list[parentIndex]; 
        if (this->_compare(child, parent)) {
            this->swap(index, parentIndex);
            index = parentIndex; 
        } else {
            done = true; 
        }
    }
}

template<class T, class Compare> 
void PriorityQueue<T, Compare>::shift_down(int index) {
    int size = this->_list.size(); 
    bool done = false; 
    while (index < (size / 2) && !done) {
        int leftIndex = index * 2; 
        int rightIndex = (index * 2) + 1; 
        T* parent = this->_list[index]; 
        T* left = this->_list[leftIndex]; 
        T* right = this->_list[rightIndex]; 
        if (this->_compare(left, right)) {
            if (this->_compare(left, parent)) {
                this->swap(leftIndex, index); 
                index = leftIndex; 
            } else {
                done = true; 
            }
        } else {
            if (this->_compare(right, parent)) {
                this->swap(rightIndex index); 
                index = rightIndex; 
            } else {
                done = true; 
            }
        }
    }
    
    if (size % 2 == 1) {
        int parentIndex = size / 2; 
        int leftIndex = size - 1; 
        T* parent = this->_list[parentIndex]; 
        T* left = this->_list[leftIndex]; 
        if (this->_compare(left, parent)) {
            this->swap(parentIndex, leftIndex); 
        }
    }
}

template<class T, class Compare> 
void PriorityQueue<T, Compare>::push(T* input) {
    this->_list.push_back(input); 
    int index = this->_list.size() - 1;
    this->_list[index]->setIndex(index); 
    this->shift_up(index);  
}

template<class T, class Compare> 
void PriorityQueue<T, Compare>::reduce(T* input) {
    int index = input.getIndex(); 
    if (this->_list[index] != input) {
        std::cerr << "Wrong index for reducing" << std::endl;
    }
    shift_up(index); 
}

template<class T, class Compare> 
Thing* PriorityQueue<T, Compare>::pop() {
    if (this->_list.size() <= 1) {
        return nullptr; 
    }
    Thing* result = this->_list[1];
    int size = this->_list.size(); 
    this->_list[1] = this->list[size - 1];
    this->_list[1]->setIndex(1); 
    this->_list.pop_back();  
    this->shift_down(1);     

    return result;  
}

template<class T, class Compare>
bool PriorityQueue<T, compare>::isEmpty() {
    int size = this->_list.size(); 
    return size <= 1
} 
#endif //SCHEDULING_PRIORITY_H
