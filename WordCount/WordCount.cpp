#include <iostream>
#include "BST.h"
#include <string>


using namespace std;

int main() {
    BST<string, int> count;
    string word;

    while(cin >> word) {
        count[word]++;
    }

    for (const auto& item: count) {
        cout << item.second << " " << item.first << endl;
    }

    return 0;
}