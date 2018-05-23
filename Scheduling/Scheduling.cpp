// Scheduling.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream> 
#include <vector>
#include <cstdlib>
#include <string>
//#include "Reader.h"
//#include "galaxy.h"

using namespace std; 

// http://forums.devshed.com/programming-42/split-lines-584595.html
typedef vector<vector<string>> Travel_Times; 

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return EXIT_FAILURE; 
	}

	string conduits = argv[1]; 
	//string routes = argv[2]; 

	ifstream input; 
	input.open(conduits);  
	if (input.is_open()) {
		string start;
		while (input >> start) {
			if (input.get() == ' ') {
				string temp; 
				input >> temp; 
				start += " " + temp; 
			}
			string destination; 
			int time;  
			input >> destination;
			if (input.get() == ' ') {
				string temp; 
				input >> temp; 
				destination += " " + temp; 
			} 
			input >> time;

			// put input into Travel_Times data structure 

			// dump input
			cerr << start << " " << destination << " " << time << endl; 
 
		}
	} else {
		return EXIT_FAILURE; 
	}

	// Reader reader(cin, constraints); 

	return EXIT_SUCCESS;
}

