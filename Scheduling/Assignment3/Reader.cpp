#include "Reader.h"


Reader::Reader(): input(std::cin), constraints(), previous_ship_id(), 
							previous_destination_planet(), previous_arrival_time(), ship_id(), 
							departure_planet(), departure_time(), destination_planet(), arrival_time(), 
							planets(), edges(), ships(), galaxy() {}

Reader::Reader(std::istream& input, Travel_Times* constraints): 
							input(input), constraints(constraints), previous_ship_id(-1), 
							previous_destination_planet(nullptr), previous_arrival_time(-1), ship_id(-1), 
							departure_planet(nullptr), departure_time(0), destination_planet(nullptr), arrival_time(0), 
							planets(), edges(), ships(), galaxy(nullptr) {
	
}

Reader::~Reader() {}

Galaxy* Reader::load() {
	this->createGalaxy(); 
	this->get_record(); 
	return this->galaxy;
}

void Reader::dumpGalaxy(int count) {
	std::cerr << "Number of Planets " << count << std::endl;  
	// check if stored data are valid. 
	count = 0; 
	for (auto& it: this->planets) {
		std::cerr << it.first << std::endl; 
		
		count ++;
	}
	

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

void Reader::createGalaxy() {
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

		Edge* edge = new Edge(destP, time); 
		startP->add(edge); 
		this->edges[startP][destP] = edge; 
		edge = new Edge(startP, time); 
		destP->add(edge);		
		this->edges[destP][startP] = edge; 
	}
	this->dumpGalaxy(count); 
}

bool Reader::get_record() {
	std::string ship;
	while (input >> ship) {
		if (ship != "#") {
			while (input.get() == ' ') {
				std::string temp; 
				input >> temp; 
				ship += " " + temp; 
			}
			std::string departure;
			input >> departure; 
			while (input.get() == ' ') {
				std::string temp; 
				input >> temp; 
				departure += " " + temp; 
			} 
			input >> this->departure_time; 
			
			std::string destination;
			input >> destination; 

			while (input.get() == ' ') {
				std::string temp; 
				input >> temp; 
				destination += " " + temp; 
			} 
			input >> this->arrival_time;

		if (this->ships.count(ship) == 0) {
			this->ship_id = this->galaxy->fleet.add(ship);
			this->ships[ship] = this->ship_id;
		} 
 
		this->departure_planet =  this->planets[departure]; 
		this->destination_planet = this->planets[destination]; 


		Leg leg(this->ship_id, this->departure_time, this->arrival_time);
		//std::cerr << this->departure_planet->name << " " << this->destination_planet->name << std::endl; 
		//std::cerr << this->edges[this->departure_planet][this->destination_planet]->destination->name << std::endl;
		this->edges[this->departure_planet][this->destination_planet]->add(leg);  
		this->dumpRoutes(); 
		this->validate(); 
		
		this->previous_ship_id = this->ship_id; 
		this->previous_destination_planet = this->destination_planet; 
		this->previous_arrival_time = this->arrival_time; 
		}
	} 
	return true;
}

void Reader::dumpRoutes() {
	std::cerr << this->ship_id << " " << this->galaxy->fleet.name(this->ship_id) << "\t"; 
	std::cerr << this->departure_planet->name << "\t" << this->departure_time 
				<< "\t" << this->destination_planet->name << "\t" << this->arrival_time << std::endl;   
}

bool Reader::validate() {
	if (this->previous_ship_id == this->ship_id) {
		if (this->previous_destination_planet != this->departure_planet) {
			std::cerr << "Invalid route structure (ship teleporting)" << std::endl; 
			exit(EXIT_FAILURE); 
		}	
		if (this->departure_time < (this->previous_arrival_time + MIN_LAYOVER_TIME)) {
			std::cerr << "Invalid route structure (layover time)" << std::endl;
			exit(EXIT_FAILURE); 
		}
		
		std::map<const Planet*, Edge*> temp = this->edges[this->departure_planet]; 
		if (temp.count(this->destination_planet) == 0) {
			std::cerr << "Invalid route structure (can't get there)" << std::endl;
			exit(EXIT_FAILURE); 
		}
	}
	return true; 
}
