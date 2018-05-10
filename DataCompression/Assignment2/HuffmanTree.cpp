//
// Created by ccomai92 on 4/29/18.
//

#include "HuffmanTree.h"


HuffmanTree::HuffmanTree() : root() {}

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
    this->dump();
}

HuffmanTree::HuffmanTree(BitInputStream& input) {
    // for verification 
    unsigned long long codes[UCHAR_MAX + 1] ={0};
    int sizes[UCHAR_MAX + 1] = {0};

    // initializing root
    this->root = new Node<unsigned char, unsigned int>();

    for (int i = 0; i < UCHAR_MAX + 1; i++) {
	unsigned char character = i;
	int size = input.getByte();
	unsigned long long code = 0; 
        if (size > 0) {	
	    for (int i = 0; i < size; i++) {
	        code = code << 1;
            code += input.getBit();
        }

	    std::bitset<64> testing(code);
	    std::cerr << "character = " << (char) i << std::endl;
	    std::cerr << "size: " <<  size << std::endl; 
	    std::cerr << "code: " << testing << std::endl;
	    this->root = this->makeTree(this->root, code, size, character);
	}
	codes[i] = code;
	sizes[i] = size;
    }
    this->dump(); 
    this->verify(codes, sizes);
}

HuffmanTree::~HuffmanTree() {
    this->clear(); 
}

void HuffmanTree::recordCodes(unsigned long long codes[], int sizes[]) {
    this->recordCodesHelper(this->root, codes, sizes, 0, 0);
    this->verify(codes, sizes);
}

void HuffmanTree::decode(BitInputStream& input, std::string outputFile, unsigned int numOfCharacters) {
    std::ofstream output; 
    output.open(outputFile); 
    if (!output.is_open()) {
    	std::cerr << "outputFile is not open" << std::endl;
    }

    for (int i = 0; i < numOfCharacters; i++) {
    	decodeHelper(this->root, input, output);
    }
    output.close(); 
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
                new Node<unsigned char, unsigned int>(frequencySum, first, second);
        priority.Push(branch);
        priority.verify();
    }
    return priority.Pop();
}

Node<unsigned char, unsigned int>* HuffmanTree::makeTree(
		Node<unsigned char, unsigned int>* current,
		unsigned long long code, int size,
	  	unsigned char character) {
    if (size == 0) {
        std::cerr << character << std::endl;
	    current = new Node<unsigned char, unsigned int>(character);
        return current;	
    }

    if (current == nullptr) {
    	current = new Node<unsigned char, unsigned int>(); 
    }

    unsigned long long bit = code & (1 << size - 1);
    bit = bit >> (size - 1);
    std::cerr << bit  << std::endl; 
    
    if (bit == 0) {
	    current->left() = makeTree(current->left(), code, size - 1, character);
    } else { // bit == 1
   	    current->right() = makeTree(current->right(), code, size - 1, character);
    }	
    return current;
}

void HuffmanTree::recordCodesHelper(Node<unsigned char, unsigned int>* current,
                                    unsigned long long codes[], int sizes[],
                                    unsigned long long code, int level) {
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

void HuffmanTree::decodeHelper(Node<unsigned char, unsigned int>* current,
	       		       BitInputStream& input, std::ofstream& output) {
    if (current != nullptr) {
    	if (current->left() == nullptr && current->right() == nullptr) {
	        unsigned char character = current->data();
	        output.put(character);
	    } else {
    	    unsigned int bit = input.getBit();
	        if (bit == 0) {
	    	    decodeHelper(current->left(), input, output);
	        } else { // bit == 1
	    	    decodeHelper(current->right(), input, output);
	        }
	    }
    }
}

void HuffmanTree::dump() {
    this->dumpHelper(this->root, 0);
}

void HuffmanTree::verify(unsigned long long codes[], int sizes[]) {
    this->verifyHelper(this->root, codes, sizes, 0, 0);
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

void HuffmanTree::verifyHelper(Node<unsigned char, unsigned int>* current,
                               unsigned long long codes[], int sizes[],
                               unsigned long long code, int level) {
    if (current != nullptr) {
        if (current->left() == nullptr && current->right() == nullptr) {
            unsigned char character = current->data();
            unsigned long long actualCode = codes[character];
            int actualSize = sizes[character];
            if (actualCode != code) {
                std::cerr << "Malformed Tree: actualCode = " << actualCode
                          << "code = " << code << std::endl;
                std::cerr << "Data = " << character << std::endl;
            }
            else if (actualSize != level) {
                std::cerr << "Malformed Tree: actualSize = " << actualSize
                          << "size = " << level << std::endl;
                std::cerr << "Data = " << character << std::endl;
            }
        }
        else {
            unsigned int currentPriority = current->priority();
            unsigned int leftPriority = current->left()->priority();
            unsigned int rightPriority = current->right()->priority();
            if (currentPriority != leftPriority + rightPriority) {
                std::cerr << "Malformed Tree: priority not matching"
                          << " parent = " << currentPriority
                          << " left = " << leftPriority
                          << " right = " << rightPriority
                          << " parent data = " << current->data() << std::endl;
            }
        }
        code = code << 1;
        this->verifyHelper(current->left(), codes, sizes, code, level + 1);
        code += 1;
        this->verifyHelper(current->right(), codes, sizes, code, level + 1);
    }
}

void HuffmanTree::clear() {
    this->root = clearHelper(this->root); 	
}

Node<unsigned char, unsigned int>* HuffmanTree::clearHelper(Node<unsigned char, unsigned int>* current) {
    if (current == nullptr) {
        return nullptr;
    } else {
        current->left() = this->clearHelper(current->left());
	    current->right() = this->clearHelper(current->right());
	    delete current;
	    return nullptr;
    }
}


