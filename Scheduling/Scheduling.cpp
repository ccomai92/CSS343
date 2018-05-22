// Scheduling.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include "Reader.h"
#include "Galaxy.h"

using namespace std; 

struct Travel_Times {
	int day;
	int hour;
};

int main(int argc, char* argv[]) {
	if (argc < 3) {
		return EXIT_FAILURE; 
	}

	string conduit = argv[1]; 
	string route = argv[2]; 

	ifstream input; 
	input.open(conduit);  
	if (input.is_open()) {
		while (!input.eof()) {
			string start;
			string destination; 
			int time; 
			input >> start >> destination >> time; 

		}
	}

	// Reader reader(cin, constraints); 

	return EXIT_SUCCESS;
}

