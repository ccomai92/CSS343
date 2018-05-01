#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <limits.h>
#include "Heap.h"
#include "HuffmanTree.h"
#include "Node.h"

using namespace std;

void dump(unsigned int frequency[]);

int main() {
    unsigned int frequency[UCHAR_MAX + 1] = {0};
    unsigned char character;
    while (cin >> character) {
        frequency[character]++;
    }

    dump(frequency);
    HuffmanTree tree(frequency);
    tree.dump();


    /*
    Heap<int> heap;


    heap.Push(3);
    heap.Push(3);
    heap.Push(7);
    heap.Push(9);
    heap.Push(12);
    heap.Push(13);
    heap.Push(14);
    heap.Push(5);

    cout << heap.verify() << endl;

    while (!heap.isEmpty()) {
        cout << heap.Pop() << endl;
    }*/

    return 0;
}

void dump(unsigned int frequency[]) {
    unsigned int maxNum = 0;
    cerr << "Character\tHEX\tprintable\tcount" << endl;
    for (int i = 0; i < UCHAR_MAX + 1; i++) {
        char character = i;
        maxNum = max(frequency[i], maxNum);
        cerr << character << "\t\t" << hex << (unsigned int) i
             << "\t" << (bool) isprint(i) << "\t\t" << dec
             << frequency[i] << endl;
    }

    for (int i = 0; i < UCHAR_MAX + 1; i++) {
        char character = i;
        cerr << character << ": ";
        unsigned int number = 50 * frequency[i] / maxNum;
        for (int j = 0; j < number; j++) {
            cerr << "*";
        }
        cerr << endl;
    }
}