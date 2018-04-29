//
// Created by ccomai92 on 4/29/18.
//

#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

#include <stack>
#include <iostream>
#include <algorithm>
#include <cmath>

template <class Key, class Value>
class AVLTree
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
        int& balanceFactor();

    private:
        Node();
        const Key _key;
        Value _value;
        int _balanceFactor;
        Node* _left;
        Node* _right;
    };
    Node* root;
    // Node* getValue(Node* current, const Key& key, Node*& result, bool& addNew);
    Node* insertHelper(Node* current, const Key& key, bool& addNew);
    Node* rotateRight(Node* current);
    Node* rotateLeft(Node* current);
    void printHelper(Node* current, int level);
    Node* clear(Node* current);
    int height(Node* node);
    bool verification(Node* current);

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
        std::pair<const Key&, Value&>& operator*();

    private:
        Node * current;
        std::pair<const Key&, Value&>* pair;
        std::stack<Node*> history;
        void leftMost(Node* node);
    };

    AVLTree();
    ~AVLTree();

    bool verification();
    void print();
    Iterator begin();
    Iterator end();
    void insert(const Key& key);
    // Value& operator[](const Key& key);
};

template<class Key, class Value>
AVLTree<Key, Value>::Node::Node(const Key& key) : _key(key), _value(Value{}),
                                                  _balanceFactor(0), _left(nullptr),
                                                  _right(nullptr) {}

template<class Key, class Value>
AVLTree<Key, Value>::Node::~Node() {}

template<class Key, class Value>
Value& AVLTree<Key, Value>::Node::value() {
    return this->_value;
}

template<class Key, class Value>
const Key& AVLTree<Key, Value>::Node::key() const {
    return this->_key;
}

template<class Key, class Value>
typename AVLTree<Key, Value>::Node*& AVLTree<Key, Value>::Node::left() {
    return this->_left;
}

template<class Key, class Value>
typename AVLTree<Key, Value>::Node*& AVLTree<Key, Value>::Node::right() {
    return this->_right;
}

template<class Key, class Value>
inline int & AVLTree<Key, Value>::Node::balanceFactor()
{
    return this->_balanceFactor;
}

template<class Key, class Value>
AVLTree<Key, Value>::Node::Node() : _key(Key{}), _value(Value{}),
                                    _left(nullptr), _right(nullptr) {}

template<class Key, class Value>
AVLTree<Key, Value>::Iterator::Iterator() : current(nullptr), pair(nullptr) {}

template<class Key, class Value>
AVLTree<Key, Value>::Iterator::Iterator(Node* node) : pair(nullptr) {
    this->leftMost(node);
}

template<class Key, class Value>
AVLTree<Key, Value>::Iterator::~Iterator() {
    delete this->pair;
    this->pair = nullptr;
}

template<class Key, class Value>
bool AVLTree<Key, Value>::Iterator::operator==(const Iterator& rhs) {
    return this->current == rhs.current;
}

template<class Key, class Value>
bool AVLTree<Key, Value>::Iterator::operator!=(const Iterator& rhs) {
    return this->current != rhs.current;
}

template<class Key, class Value>
typename AVLTree<Key, Value>::Iterator& AVLTree<Key, Value>::Iterator::operator++() {
    this->history.pop();
    this->leftMost(this->current->right());
    if (this->history.empty()) {
        this->current = nullptr;
    }
    else {
        this->current = this->history.top();
    }
    return *this;
}

template<class Key, class Value>
std::pair<const Key&, Value&>& AVLTree<Key, Value>::Iterator::operator*() {
    this->pair = new std::pair<const Key&, Value&>(this->current->key(),
                                                   this->current->value());
    return *this->pair;
}

template<class Key, class Value>
void AVLTree<Key, Value>::Iterator::leftMost(Node* node) {
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
AVLTree<Key, Value>::AVLTree() : root(nullptr) {}

template<class Key, class Value>
AVLTree<Key, Value>::~AVLTree() {
    this->root = this->clear(this->root);
}

template<class Key, class Value>
typename AVLTree<Key, Value>::Iterator AVLTree<Key, Value>::begin() {
    return AVLTree<Key, Value>::Iterator(this->root);
}

template<class Key, class Value>
typename AVLTree<Key, Value>::Iterator AVLTree<Key, Value>::end() {
    return AVLTree<Key, Value>::Iterator();
}

/*
template<class Key, class Value>
Value& AVLTree<Key, Value>::operator[](const Key& key) {
	Node* result = nullptr;
	bool addNew = false;
	this->root = this->getValue(this->root, key, result, addNew);
	return result->value();
}

template<class Key, class Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::getValue(
										Node* current, const Key& key,
										Node*& result, bool& addNew) {
	if (current == nullptr) {
		current = new Node(key);
		result = current;
		addNew = true;
		return current;
	}

	if (current->key() == key) {
		result = current;
	}
	else if (current->key() > key) {
		if (current->left() == nullptr) {
			current->left() = this->getValue(current->left(), key, result, addNew);
			if (current->right() == nullptr) {
				addNew = true;
			}
			current->balanceFactor()--;

		}
		else {
			if (current->left()->key() == key) {
				result = current->left();
			}
			else if (current->left()->key() > key) {
					current->left()->left() = this->getValue(current->left()->left(), key, result, addNew);
					if (addNew) {
						current->balanceFactor()--;
						current->left()->balanceFactor()--;
					}
					if (current->left()->balanceFactor() == -2) {
						current->left() = this->rotateRight(current->left());
					}
			}
			else {
				current->left()->right() = this->getValue(current->left()->right(), key, result, addNew);
				if (addNew) {
					current->balanceFactor()--;
					current->left()->balanceFactor()++;
				}
				if (current->left()->balanceFactor() == 2) {
					current->left() = this->rotateLeft(current->left());
				}
			}
			if (current->balanceFactor() == -2) {
				current = this->rotateRight(current);
			}
		}
	}
	else if (current->key() < key) {
		if (current->right() == nullptr) {
			current->right() = this->getValue(current->right(), key, result, addNew);
			if (current->left() == nullptr) {
				addNew = true;
			}
			current->balanceFactor()++;
		}
		else {
			if (current->right()->key() == key) {
				result = current->right();
			}
			else if (current->right()->key() > key) {
				current->right()->left() = this->getValue(current->right()->left(), key, result, addNew);
				if (addNew) {
					current->balanceFactor()++;
					current->right()->balanceFactor()--;
				}
				if (current->right()->balanceFactor() == -2) {
					current->right() = this->rotateRight(current->right());
				}
			}
			else {
				current->right()->right() = this->getValue(current->right()->right(), key, result, addNew);
				if (addNew) {
					current->balanceFactor()++;
					current->right()->balanceFactor()++;
				}
				if (current->right()->balanceFactor() == 2) {
					current->right() = this->rotateLeft(current->right());
				}
			}
			if (current->balanceFactor() == 2) {
				current = this->rotateLeft(current);
			}
		}
	}

	return current;
}*/

template<class Key, class Value>
inline void AVLTree<Key, Value>::insert(const Key & key)
{
    bool addNew = false;
    this->root = this->insertHelper(this->root, key, addNew);
}

template<class Key, class Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::insertHelper(Node * current, const Key & key, bool& addNew)
{
    if (current == nullptr) {
        Node* result = new Node(key);
        result->value()++;
        addNew = true;
        return result;
    }

    if (current->key() == key) {
        current->value()++;
    }
    else if (current->key() < key) {
        current->right() = insertHelper(current->right(), key, addNew);
        if (addNew) {
            if (current->balanceFactor() < 0) {
                addNew = false;
            }
            current->balanceFactor()++;
        }
        if (current->balanceFactor() == 2) {
            if (current->right()->key() > key) { //RL
                current->right() = this->rotateRight(current->right());
            }
            current = this->rotateLeft(current);
            if (current->balanceFactor() == 0)
                addNew = false;
        }
    }
    else {
        current->left() = insertHelper(current->left(), key, addNew);
        if (addNew) {
            if (current->balanceFactor() > 0) {
                addNew = false;
            }
            current->balanceFactor()--;
        }

        if (current->balanceFactor() == -2) {
            if (current->left()->key() < key) { // LR
                current->left() = this->rotateLeft(current->left());
            }
            current = this->rotateRight(current);
            if (current->balanceFactor() == 0)
                addNew = false;
        }
    }
    return current;
}

template<class Key, class Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::rotateRight(Node* current) {
    Node* left = current->left();
    current->left() = left->right();
    left->right() = current;

    current->balanceFactor() += (1 - std::min(left->balanceFactor(), 0));
    left->balanceFactor() += (1 + std::max(current->balanceFactor(), 0));

    return left;
}

template<class Key, class Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::rotateLeft(Node* current) {
    Node* right = current->right();
    current->right() = right->left();
    right->left() = current;

    current->balanceFactor() -= (1 + std::max(right->balanceFactor(), 0));
    right->balanceFactor() -= (1 - std::min(current->balanceFactor(), 0));

    return right;
}

template<class Key, class Value>
inline bool AVLTree<Key, Value>::verification(Node* current)
{
    if (current == nullptr) {
        return true;
    }
    int leftHeight = height(current->left());
    int rightHeight = height(current->right());
    std::cout << leftHeight << std::endl;
    std::cout << rightHeight << std::endl;
    std::cout << std::endl;
    if (std::abs(leftHeight - rightHeight) <= 1
        && verification(current->left())
        && verification(current->right())) {
        return true;
    }
    return false;

}

template<class Key, class Value>
inline bool AVLTree<Key, Value>::verification()
{
    return verification(this->root);
}

template<class Key, class Value>
void AVLTree<Key, Value>::print() {
    this->printHelper(this->root, 0);
}

template<class Key, class Value>
void AVLTree<Key, Value>::printHelper(Node *current, int level) {
    if (current != nullptr) {
        this->printHelper(current->right(), level + 1);
        for (int i = 0; i < level; i++) {
            std::cout << "\t";
        }
        std::cout << current->key()
                  << " " << current->value()
                  << " " << current->balanceFactor()
                  << " " <<std::endl;
        this->printHelper(current->left(), level + 1);
    }
}

template<class Key, class Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::clear(Node* current) {
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

template<class Key, class Value>
inline int AVLTree<Key, Value>::height(Node * node)
{
    if (node == nullptr) {
        return 0;
    }
    return 1 + std::max(height(node->left()), height(node->right()));
}




#endif //AVLTREE_AVLTREE_H
