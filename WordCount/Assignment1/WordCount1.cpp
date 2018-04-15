#include <iostream>
#include "BST.h"
#include <string>
#include <vector>


using namespace std;

int main() {
    BST<string, int> count;
    string word;

    while(cin >> word) {
        count[word]++;
    }

    count.print();

    for (auto& item: count) {
        cout << item.second << " " << item.first << endl;
    }
    return 0;
}