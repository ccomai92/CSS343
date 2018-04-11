//
// Created by ccomai92 on 4/6/18.
//

#ifndef WORDCOUNT_BST_H
#define WORDCOUNT_BST_H

#include <stack>
#include <string>
#include <iostream>

template <class Key, class Value>
class BST
{
private:
    class Node {
    public:
        Node(const Key& key);
        ~Node();

        Value& value();
        const Key& key() const;
        Node*& left();
        Node*& right();

    private:
        Node();
        const Key _key;
        Value _value;
        Node* _left;
        Node* _right;
    };
    Node* root;
    Value& getValue(Node* current, const Key& key);
    Node* clear(Node* current);

public:
    class Iterator
    {
    public:
        Iterator();
        Iterator(Node* node);
        ~Iterator();

        bool operator==(const Iterator& rhs);
        bool operator!=(const Iterator& rhs);
        Iterator& operator++(); // prifix increment
        std::pair<const Key&, Value&> operator*();

    private:
        Node* current;
        std::stack<Node*> history;

        void leftMost(Node* node);

    };

    BST();
    ~BST();

    //void print();
    //void printHelper(Node<Key, Value>* current);
    Iterator begin();
    Iterator end();
    Value& operator[](const Key& key);
};

template<class Key, class Value>
BST<Key, Value>::Node::Node(const Key& key): _key(key), _value(Value{}),
                                 _left(nullptr), _right(nullptr) {}

template<class Key, class Value>
BST<Key, Value>::Node::~Node() {}

template<class Key, class Value>
Value& BST<Key, Value>::Node::value() {
    return this->_value;
}

template<class Key, class Value>
const Key& BST<Key, Value>::Node::key() const {
    return this->_key;
}

template<class Key, class Value>
typename BST<Key, Value>::Node*& BST<Key, Value>::Node::left() {
    return this->_left;
}

template<class Key, class Value>
typename BST<Key, Value>::Node*& BST<Key, Value>::Node::right() {
    return this->_right;
}

template<class Key, class Value>
BST<Key, Value>::Node::Node(): _key(Key{}), _value(Value{}),
                               _left(nullptr), _right(nullptr){}

template<class Key, class Value>
BST<Key, Value>::Iterator::Iterator(): current(nullptr) {}

template<class Key, class Value>
BST<Key, Value>::Iterator::Iterator(Node* node) {
    this->leftMost(node);
}

template<class Key, class Value>
BST<Key, Value>::Iterator::~Iterator() {}

template<class Key, class Value>
bool BST<Key, Value>::Iterator::operator==(const Iterator & rhs) {
    return this->current == rhs.current;
}

template<class Key, class Value>
bool BST<Key, Value>::Iterator::operator!=(const Iterator & rhs) {
    return this->current != rhs.current;
}

template<class Key, class Value>
typename BST<Key, Value>::Iterator& BST<Key, Value>::Iterator::operator++() {
    this->history.pop();
    this->leftMost(this->current->right());
    if (this->history.empty()) {
        this->current = nullptr;
    } else {
        this->current = this->history.top();
    }
    return *this;
}

template<class Key, class Value>
std::pair<const Key&, Value&> BST<Key, Value>::Iterator::operator*() {
    return std::pair<const Key&, Value&>(this->current->key(),
                                         this->current->value());
}

template<class Key, class Value>
void BST<Key, Value>::Iterator::leftMost(Node* node) {
    if (node == nullptr) {
        this->current = nullptr;
    }
    else {
        while (node != nullptr) {
            this->history.push(node);
            if (node->left() == nullptr) {
                this->current = node;
            }
            node = node->left();
        }
    }
}

template<class Key, class Value>
BST<Key, Value>::BST(): root(nullptr) {}

template<class Key, class Value>
BST<Key, Value>::~BST() {
    this->root = this->clear(this->root);
}

template<class Key, class Value>
typename BST<Key, Value>::Iterator BST<Key, Value>::begin() {
    return Iterator(this->root);
}

template<class Key, class Value>
typename BST<Key, Value>::Iterator BST<Key, Value>::end() {
    return Iterator();
}

template<class Key, class Value>
Value& BST<Key, Value>::operator[](const Key& key) {
    if (this->root == nullptr) {
        this->root = new Node(key);
        return this->root->value();
    }
    return this->getValue(this->root, key);
}

template<class Key, class Value>
Value & BST<Key, Value>::getValue(Node* current, const Key& key) {
    if (current->key() == key) {
        return current->value();
    }
    else if (current->key() < key) {
        if (current->right() == nullptr) {
            current->right() = new Node(key);
            return current->right()->value();
        }
        return this->getValue(current->right(), key);
    }
    else {
        if (current->left() == nullptr) {
            current->left() = new Node(key);
            return current->left()->value();
        }
        return this->getValue(current->left(), key);
    }
}

template<class Key, class Value>
typename BST<Key, Value>::Node* BST<Key, Value>::clear(Node* current) {
    if (current == nullptr) {
        return nullptr;
    }
    else {
        current->left() = clear(current->left());
        current->right() = clear(current->right());
        delete current;
        return nullptr;
    }
}

#endif //WORDCOUNT_BST_H
