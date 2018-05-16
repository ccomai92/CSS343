//
// Created by ccomai92 on 5/16/18.
//

#ifndef DATACOMPRESSION_HUFFMANNODE_H
#define DATACOMPRESSION_HUFFMANNODE_H

#include <algorithm>
#include <functional>
#include <iostream>

class HuffmanNode {
    friend std::ostream& operator<<(std::ostream& output, const HuffmanNode& rhs) {
        if (rhs._data != 0) {
            output << "("  << rhs._data << ", ";
        } else {
            output << "(";
        }
        output << rhs._frequency << ")";
        return output;
    }

public:
    HuffmanNode();
    HuffmanNode(unsigned char data);
    HuffmanNode(unsigned int frequency, HuffmanNode* left, HuffmanNode* right);
    HuffmanNode(unsigned char data, unsigned int frequency);
    ~HuffmanNode();

    unsigned char& data();
    const unsigned int& frequency() const;
    HuffmanNode*& left();
    HuffmanNode*& right();

    bool operator==(const HuffmanNode& rhs);
    bool operator!=(const HuffmanNode& rhs);
    bool operator>(const HuffmanNode& rhs);
    bool operator>=(const HuffmanNode& rhs);
    bool operator<(const HuffmanNode& rhs);
    bool operator<=(const HuffmanNode& rhs);

private:
    unsigned char _data;
    unsigned int _frequency;
    HuffmanNode* _left;
    HuffmanNode* _right;
};

struct CompareNode: public std::binary_function<HuffmanNode*, HuffmanNode*, bool> {
    bool operator()(const HuffmanNode* lhs, const HuffmanNode* rhs) {
        return lhs->frequency() < rhs->frequency();
    }
};

inline HuffmanNode::HuffmanNode(): _data(0), _frequency(0), _left(nullptr), _right(nullptr) {}

inline HuffmanNode::HuffmanNode(unsigned char data): _data(data), _frequency(0), _left(nullptr), _right(nullptr) {}

inline HuffmanNode::HuffmanNode(unsigned int frequency, HuffmanNode* left, HuffmanNode* right):
                            _data(0), _frequency(frequency),
                            _left(left), _right(right) {}

inline HuffmanNode::HuffmanNode(unsigned char data, unsigned int frequency):
                            _data(data), _frequency(frequency),
                            _left(nullptr), _right(nullptr) {}

inline HuffmanNode::~HuffmanNode() {}

inline bool HuffmanNode::operator==(const HuffmanNode& rhs) {
    return this->_frequency == rhs._frequency;
}

inline bool HuffmanNode::operator!=(const HuffmanNode& rhs) {
    return this->_frequency != rhs._frequency;
}

inline bool HuffmanNode::operator>(const HuffmanNode& rhs) {
    return this->_frequency > rhs._frequency;
}

inline bool HuffmanNode::operator>=(const HuffmanNode& rhs) {
    return this->_frequency > rhs._frequency
           || this->_frequency == rhs._frequency;
}

inline bool HuffmanNode::operator<(const HuffmanNode& rhs) {
    return this->_frequency < rhs._frequency;
}

inline bool HuffmanNode::operator<=(const HuffmanNode& rhs) {
    return this->_frequency < rhs._frequency
           || this->_frequency == rhs._frequency;
}

inline unsigned char& HuffmanNode::data() {
    return this->_data;
}

inline const unsigned int& HuffmanNode::frequency() const {
    return this->_frequency;
}

inline HuffmanNode*& HuffmanNode::left() {
    return this->_left;
}

inline HuffmanNode*& HuffmanNode::right() {
    return this->_right;
}

#endif //DATACOMPRESSION_HUFFMANNODE_H
