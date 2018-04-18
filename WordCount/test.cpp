#include "BST.h" 
#include "Treap.h" 
#include <iostream> 
#include <vector> 
#include <string> 

using namespace std; 

int main() {
	BST<string, int> count1; 
	Treap<string, int> count2; 
	vector<string> list; 

	list.push_back("a"); 
	list.push_back("b");
	list.push_back("c");
	list.push_back("d");
	list.push_back("e");
	list.push_back("f");
	list.push_back("g");
	list.push_back("h");
	list.push_back("i");

	int size = list.size(); 
	for (int i = 0; i < size; i++) {
		string word = list[i]; 
		count1[word]++; 
		count2[word]++; 
	}

	count1.print(); 
	count2.print(); 

	return 0; 
}
