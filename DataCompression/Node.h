//
// Created by ccomai92 on 4/30/18.
//

#ifndef DATACOMPRESSION_NODE_H
#define DATACOMPRESSION_NODE_H

#include <iostream>

template<class Data, class Priority>
class Node {
    friend std::ostream& operator<<(std::ostream& output,
                                    const Node<Data, Priority>& rhs){
        if (rhs._data != Data{}) {
            output << "(" << rhs._data << " , ";
        }
        output << rhs._priority << ")";
        return output;
    }

public:
    Node();
    Node(Priority priority, Node<Data, Priority>* left,
                            Node<Data, Priority>* right);
    Node(Data data, Priority priority);
    ~Node();


    Data& data();
    Priority& priority();
    Node<Data, Priority>*& left();
    Node<Data, Priority>*& right();


    bool operator==(Node& rhs);
    bool operator!=(Node& rhs);
    bool operator>(Node& rhs);
    bool operator>=(Node& rhs);
    bool operator<(Node& rhs);
    bool operator<=(Node& rhs);
private:
    Data _data;
    Priority _priority;
    Node<Data, Priority>* _left;
    Node<Data, Priority>* _right;
};

template<class Data, class Priority>
Node<Data, Priority>::Node(): _data(Data{}), _priority(Priority{}),
                              _left(nullptr), _right(nullptr) {}

template<class Data, class Priority>
Node<Data, Priority>::Node(Priority priority, Node<Data, Priority>* left,
                           Node<Data, Priority>* right):
        _data(Data{}), _priority(priority), _left(left), _right(right) {}

template<class Data, class Priority>
Node<Data, Priority>::Node(Data data, Priority priority): _data(data), _priority(priority),
                                                          _left(nullptr), _right(nullptr) {}

template<class Data, class Priority>
Node<Data, Priority>::~Node() {}

template<class Data, class Priority>
bool Node<Data, Priority>::operator==(Node<Data, Priority>& rhs) {
    return this->_priority == rhs._priority;
}

template<class Data, class Priority>
bool Node<Data, Priority>::operator!=(Node<Data, Priority>& rhs) {
    return this->_priority != rhs._priority;
}

template<class Data, class Priority>
bool Node<Data, Priority>::operator>(Node<Data, Priority>& rhs) {
    return this->_priority > rhs._priority;
}

template<class Data, class Priority>
bool Node<Data, Priority>::operator>=(Node<Data, Priority>& rhs) {
    return this->_priority > rhs._priority
            || this->_priority == rhs._priority;
}

template<class Data, class Priority>
bool Node<Data, Priority>::operator<(Node<Data, Priority>& rhs) {
    return this->_priority < rhs._priority;
}

template<class Data, class Priority>
bool Node<Data, Priority>::operator<=(Node<Data, Priority>& rhs) {
    return this->_priority < rhs._priority
            || this->_priority == rhs._priority;
}

template<class Data, class Priority>
Data& Node<Data, Priority>::data() {
    return this->_data;
}

template<class Data, class Priority>
Priority& Node<Data, Priority>::priority() {
    return this->_priority;
}

template<class Data, class Priority>
Node<Data, Priority>*& Node<Data, Priority>::left() {
    return this->_left;
}

template<class Data, class Priority>
Node<Data, Priority>*& Node<Data, Priority>::right() {
    return this->_right;
}



#endif //DATACOMPRESSION_NODE_H
