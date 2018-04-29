#include "AVLTree.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    AVLTree<string, int> dictionary;
    vector<string> words;

    words.push_back("aag");
    words.push_back("dsagb");
    words.push_back("fdc");
    words.push_back("hgkfd");
    words.push_back("gdde");
    words.push_back("qwef");
    words.push_back("yrerug");
    words.push_back("utruh");
    words.push_back("qwerti");
    words.push_back("tititj");
    words.push_back("zxcvk");

    words.push_back("adl");
    words.push_back("kuy");
    words.push_back("jotyu");
    words.push_back("rtyi");
    words.push_back("piyh");
    words.push_back("qrtewh");
    words.push_back("bvcxi");
    words.push_back("jhg");
    words.push_back("ffghj");
    words.push_back("edsa");
    words.push_back("qwerd");
    words.push_back("czxc");
    words.push_back("brw");
    words.push_back("asdf");
    /*
    words.push_back("d");
    words.push_back("u");
    words.push_back("v");
    words.push_back("w");
    words.push_back("x");
    words.push_back("q");
    words.push_back("e");
    words.push_back("f");
    words.push_back("g");
    words.push_back("h");
    words.push_back("a");
    words.push_back("b");
    words.push_back("c");
    words.push_back("i");
    words.push_back("j");
    words.push_back("k");
    words.push_back("u");
    words.push_back("v");
    words.push_back("w");
    words.push_back("x");
    words.push_back("y");
    words.push_back("l");
    words.push_back("r");
    words.push_back("s");
    words.push_back("t");
    */

    int size = words.size();
    for (int i = 0; i < size; i++) {
        string word = words[i];
        dictionary.insert(word);
        cout << " input :  " << word << endl;
        dictionary.print();
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
    }

    dictionary.print();
    cout << dictionary.verification() << endl;
    return 0;
}