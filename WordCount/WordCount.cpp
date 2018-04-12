#include <iostream>
#include "Treap.h"
#include <string>
#include <vector>


using namespace std;

int main() {
    Treap<string, int> count;
    vector<string> words;
    words.push_back("a");
    words.push_back("b");
    words.push_back("c");
    words.push_back("d");
    words.push_back("e");
    words.push_back("f");
    words.push_back("g");
    words.push_back("h");
    words.push_back("i");
    for (int i = 0; i < 9; i++) {
        count[words[i]]++;
    }

    // string word;

    /*
    while(cin >> word) {
        count[word]++;
    }

    for (const auto& item: count) {
        cout << item.second << " " << item.first << endl;
    }*/

    count.print();

    return 0;
}