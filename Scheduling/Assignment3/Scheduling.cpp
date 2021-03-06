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
		if (start != "#") {
			while (input.get() == ' ') {
				string temp; 
				input >> temp; 
				start += " " + temp; 
			}
			string destination; 
			int time;  
			input >> destination;

			while (input.get() == ' ') {
				string temp; 
				input >> temp; 
				destination += " " + temp; 
			} 
			input >> time;

			// put input into Travel_Times data structure
			constraints->starts.push_back(start); 
			constraints->destinations.push_back(destination); 
			constraints->times.push_back(time);  
			constraints->size++;
		}
	}
} 

void dump(Travel_Times* constraints) { 
	for (int i = 0; i < constraints->size; i++) {
		cerr << constraints->starts[i] 
			<< "\t" << constraints->destinations[i]
			<< "\t" << constraints->times[i] << endl; 
	}
}