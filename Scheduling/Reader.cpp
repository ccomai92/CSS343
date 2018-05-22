#include "stdafx.h"
#include "Reader.h"


Reader::Reader() {}

Reader::~Reader() {}

Reader::Reader(std::ifstream& input, Travel_Times* constraints): 
							input(input), constraints(constraints), current_input_line(), previous_ship_id(), 
							previous_destination_planet(), previous_arrival_time(), ship_id(), 
							departure_planet(), departure_time(), destination_planet(), arrival_time(), 
							planets(), edges(), ships(), galaxy() {
	
	
}

Galaxy* Reader::load() {
	return nullptr;
}

bool Reader::get_record() {
	return false;
}

bool Reader::validate() {
	return false;
}
