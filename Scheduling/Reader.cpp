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
	
}

Reader::~Reader() {}

Galaxy* Reader::load() {
	this->galaxy = new Galaxy(); 
	int count = 0; 
	for (int i = 0; i < this->constraints->size; i++) {
		std::string start = this->constraints->starts[i];
		std::string destination = this->constraints->destinations[i];
		int time = this->constraints->times[i]; 
		
		Planet* startP;
		Planet* destP; 
		
		// reference: stack overflow 
		// https://stackoverflow.com/questions/3136520/determine-if-map-contains-a-value-for-a-key
		if (this->planets.count(start) == 0) {
			count++; 
			startP = new Planet(start); 
			this->planets[start] = startP; 
			this->galaxy->add(startP); 
		} else {
			startP = this->planets[start]; 
		}

		// reference: stack overflow 
		// https://stackoverflow.com/questions/3136520/determine-if-map-contains-a-value-for-a-key
		if (this->planets.count(destination) == 0) {
			count++; 
			destP = new Planet(destination);
			this->planets[destination] = destP;  
			this->galaxy->add(destP); 
		} else {
			destP = this->planets[destination]; 
		}

		Edge* edge = new Edge(destP); 
		Leg leg; 
		edge->add(leg);
		startP->add(edge); 
		this->edges[startP][destP] = edge; 		
	}

	std::cerr << "Number of Planets " << count << std::endl;  
	// check if stored data are valid. 
	count = 0; 
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
	return this->galaxy;
}

bool Reader::get_record() {
	return false;
}

bool Reader::validate() {
	return false;
}
