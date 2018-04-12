//
// Created by ccomai92 on 4/11/18.
//

#ifndef WORDCOUNT_TREAP_H
#define WORDCOUNT_TREAP_H


#include <stack>
#include <random>

template <class Key, class Value>
class Treap
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
        const int& priority() const;

    private:
        Node();
        const Key _key;
        Value _value;
        Node* _left;
        Node* _right;
        int _priority;
    };
    Node* root;
    Node* getValue(Node* current,
                    const Key& key, Node*& result);
    Node* rotateRight(Node* current);
    Node* rotateLeft(Node* current);
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

    Treap();
    ~Treap();

    void print();
    void printHelper(Node* current, int level);
    Iterator begin();
    Iterator end();
    Value& operator[](const Key& key);
};

template<class Key, class Value>
Treap<Key, Value>::Node::Node(const Key& key): _key(key), _value(Value{}),
                                               _left(nullptr), _right(nullptr) {
    std::random_device r;
    std::default_random_engine e(r());
    std::uniform_int_distribution<int> randomN(0, 2147483647);
    this->_priority = randomN(e);

}

template<class Key, class Value>
Treap<Key, Value>::Node::~Node() {}

template<class Key, class Value>
Value& Treap<Key, Value>::Node::value() {
    return this->_value;
}

template<class Key, class Value>
const Key& Treap<Key, Value>::Node::key() const {
    return this->_key;
}

template<class Key, class Value>
typename Treap<Key, Value>::Node*& Treap<Key, Value>::Node::left() {
    return this->_left;
}

template<class Key, class Value>
typename Treap<Key, Value>::Node*& Treap<Key, Value>::Node::right() {
    return this->_right;
}

template<class Key, class Value>
Treap<Key, Value>::Node::Node(): _key(Key{}), _value(Value{}),
                                 _priority(), _left(nullptr),
                                 _right(nullptr){}

template<class Key, class Value>
const int &Treap<Key, Value>::Node::priority() const {
    return this->_priority;
}

template<class Key, class Value>
Treap<Key, Value>::Iterator::Iterator(): current(nullptr) {}

template<class Key, class Value>
Treap<Key, Value>::Iterator::Iterator(Node* node) {
    this->leftMost(node);
}

template<class Key, class Value>
Treap<Key, Value>::Iterator::~Iterator() {}

template<class Key, class Value>
bool Treap<Key, Value>::Iterator::operator==(const Iterator & rhs) {
    return this->current == rhs.current;
}

template<class Key, class Value>
bool Treap<Key, Value>::Iterator::operator!=(const Iterator & rhs) {
    return this->current != rhs.current;
}

template<class Key, class Value>
typename Treap<Key, Value>::Iterator& Treap<Key, Value>::Iterator::operator++() {
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
std::pair<const Key&, Value&> Treap<Key, Value>::Iterator::operator*() {
    return std::pair<const Key&, Value&>(this->current->key(),
                                         this->current->value());
}

template<class Key, class Value>
void Treap<Key, Value>::Iterator::leftMost(Node* node) {
    if (node == nullptr) {
        this->current = nullptr;
    } else {
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
Treap<Key, Value>::Treap(): root(nullptr) {}

template<class Key, class Value>
Treap<Key, Value>::~Treap() {
    this->root = this->clear(this->root);
}

template<class Key, class Value>
typename Treap<Key, Value>::Iterator Treap<Key, Value>::begin() {
    return Iterator(this->root);
}

template<class Key, class Value>
typename Treap<Key, Value>::Iterator Treap<Key, Value>::end() {
    return Iterator();
}

template<class Key, class Value>
Value& Treap<Key, Value>::operator[](const Key& key) {
    Node* result = nullptr;
    this->root = this->getValue(this->root, key, result);
    return result->value();
}

template<class Key, class Value>
typename Treap<Key, Value>::Node* Treap<Key, Value>::getValue(
                 Node* current, const Key& key, Node*& result) {
    if (current == nullptr) {
        current = new Node(key);
        result = current;
        return current;
    }

    if (current->key() == key) {
        result = current;
    } else if (current->key() > key) {
        current->left() = this->getValue(current->left(), key, result);
        if (current->left()->priority() < current->priority()) {
            current = this->rotateRight(current);
        }
    } else {
        current->right() = this->getValue(current->right(), key, result);
        if (current->right()->priority() < current->priority()) {
            current = this->rotateLeft(current);
        }
    }
    return current;
}

template<class Key, class Value>
typename Treap<Key, Value>::Node* Treap<Key, Value>::clear(Node* current) {
    if (current == nullptr) {
        return nullptr;
    } else {
        current->left() = clear(current->left());
        current->right() = clear(current->right());
        delete current;
        return nullptr;
    }
}

template<class Key, class Value>
typename Treap<Key, Value>::Node* Treap<Key, Value>::rotateRight(Node* current) {
    Node* left = current->left();
    current->left() = current->left()->right();
    left->right() = current;
    return left;
}

template<class Key, class Value>
typename Treap<Key, Value>::Node* Treap<Key, Value>::rotateLeft(Node* current) {
    Node* right = current->right();
    current->right() = current->right()->left();
    right->left() = current;
    return right;
}

template<class Key, class Value>
void Treap<Key, Value>::print() {
    printHelper(this->root, 0);
}

template<class Key, class Value>
void Treap<Key, Value>::printHelper(Node *current, int level) {
    if (current != nullptr) {
        printHelper(current->right(), level + 1);
        for (int i = 0; i < level; i++) {
            std::cout << "\t";
        }
        std::cout << current->key() << " " << current->value() << " " <<
                  current->priority() << std::endl;
        printHelper(current->left(), level + 1);
    }
}


#endif //WORDCOUNT_TREAP_H
