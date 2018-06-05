// Scheduling.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <fstream> 
#include <cstdlib>
#include <string>
#include "Reader.h"
#include "Galaxy.h"

using namespace std; 


void readConduits(ifstream& input, Travel_Times* constraints); 
void dump(Travel_Times* constraints); 

int main(int argc, char* argv[]) {
	if (argc < 3) {
		return EXIT_FAILURE; 
	}

	string conduits = argv[1]; 
	string routes = argv[2]; 

	ifstream input; 

	// open conduits.txt 
	input.open(conduits);  
	Travel_Times* constraints = new Travel_Times(); 
	if (input.is_open()) {
		readConduits(input, constraints);
	} else {
		return EXIT_FAILURE; 
	}
	input.close(); 
	dump(constraints);

	// open routes.txt
	input.open(routes); 
	if (!input.is_open()) {
		return EXIT_FAILURE; 
	}

	Reader reader(input, constraints); 
	Galaxy* galaxy = reader.load(); 
	galaxy->dump(); 
	//galaxy->dump_routes();
	galaxy->search(); 

	input.close(); 
	return EXIT_SUCCESS;
}

void readConduits(ifstream& input, Travel_Times* constraints) {
	string start;
	while (input >> start) {
		if (input.fail() || input.bad()) {
			exit(EXIT_FAILURE); 
		}
		while (input.get() == ' ') {
			if (input.fail() || input.bad()) {
				exit(EXIT_FAILURE); 
			}
			string temp; 
			input >> temp; 
			if (input.fail() || input.bad()) {
				exit(EXIT_FAILURE); 
			}
			start += " " + temp; 
		}
		string destination; 
		int time;  
		input >> destination;
		if (input.fail() || input.bad()) {
			exit(EXIT_FAILURE);
		}

		while (input.get() == ' ') {
			if (input.fail() || input.bad()) {
				exit(EXIT_FAILURE);
			}
			string temp; 
			input >> temp; 
			if (input.fail() || input.bad()) {
				exit(EXIT_FAILURE);
			}
			destination += " " + temp; 
		} 
		input >> time;
		if (input.fail() || input.bad()) {
			exit(EXIT_FAILURE);
		}

		// put input into Travel_Times data structure
		constraints->starts.push_back(start); 
		constraints->destinations.push_back(destination); 
		constraints->times.push_back(time);  
		constraints->size++;
	}
} 

void dump(Travel_Times* constraints) { 
	for (int i = 0; i < constraints->size; i++) {
		cerr << constraints->starts[i] 
			<< "\t" << constraints->destinations[i]
			<< "\t" << constraints->times[i] << endl; 
	}
}