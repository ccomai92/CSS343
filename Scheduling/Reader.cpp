#include "Reader.h"


Reader::Reader(): input(std::cin), constraints(), current_input_line(), previous_ship_id(), 
							previous_destination_planet(), previous_arrival_time(), ship_id(), 
							departure_planet(), departure_time(), destination_planet(), arrival_time(), 
							planets(), edges(), ships(), galaxy() {}

Reader::Reader(std::istream& input, Travel_Times* constraints): 
							input(input), constraints(constraints), current_input_line(), previous_ship_id(), 
							previous_destination_planet(), previous_arrival_time(), ship_id(), 
							departure_planet(), departure_time(), destination_planet(), arrival_time(), 
							planets(), edges(), ships(), galaxy() {
	this->createGalaxy(); 
	
}

Reader::~Reader() {}

Galaxy* Reader::load() {
	
	return this->galaxy;
}

void Reader::createGalaxy() {
	for (int i = 0; i < this->constraints->size; i++) {
		std::string start = this->constraints->starts[i];
		std::string destination = this->constraints->destinations[i];
		int time = this->constraints->times[i]; 
		
		Planet* startP = this->planets[start]; 
		Planet* destP = this->planets[destination]; 
		
		if (!startP) {
			startP = new Planet(start); 
		}

		if (!destP) {
			destP = new Planet(destination); 
		}

		Edge* edge = new Edge(destP); 
		this->edges[startP][destP] = edge; 		
	}
	// check if stored data are valid. 
	int count = 0; 
	for (auto& it: this->planets) {
		std::cerr << it.first << std::endl; 
		
		count ++;
	}
	std::cerr << "Number of planets: " << count << std::endl; 

	for (auto& it: this->edges) {
		std::cerr << "Start: " << it.first->name << std::endl;
		for (auto& it2: it.second) {
			std::cerr << "Destination: " << it2.first->name << std::endl; 
			std::cerr << "EdgeDestination: " 
				<< it2.second->destination->name << std::endl; 
		}		
		std::cerr << std::endl;
	}

}

bool Reader::get_record() {
	return false;
}

bool Reader::validate() {
	return false;
}
