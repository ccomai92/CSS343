// Author: Morris Bernstein (morris@systems-deployment.com)
// Modified by Kris Kwon


#ifndef READER_H
#define READER_H

#include <string>
#include <map>
#include <fstream>
#include <iostream> 
#include <vector>
#include "Galaxy.h"

struct Travel_Times {
	std::vector<std::string> starts; 
	std::vector<std::string> destinations; 
	std::vector<int> times; 
	int size = 0; 
};

// typedef std::map<std::string, std::map<std::string, int>> Travel_Times;   

class Reader {
public:
	Reader();
	Reader(std::istream& input, Travel_Times* constraints);
	~Reader(); 

	Galaxy* load();

private:
	static const int MIN_LAYOVER_TIME = 4;

	void createGalaxy(); 

	// Read next leg of ship's route
	bool get_record();

	// Verify that that current leg is a valid continuation of the
	// previous leg or the beginning of the route for another ship.
	bool validate();

	std::istream& input;
	// Data structure holding the travel times between planets.
	Travel_Times* constraints;
	// Input string representing a single leg.
	// std::string current_input_line;

	// Previous leg information for validation.
	Ship_ID previous_ship_id;
	Planet* previous_destination_planet;
	int previous_arrival_time;

	// Current leg information
	Ship_ID ship_id;
	Planet* departure_planet;
	Time departure_time;
	Planet* destination_planet;
	Time arrival_time;

	// Planet name to planet object
	std::map<std::string, Planet*> planets;

	// Planet-name pair to edge object
	std::map<const Planet*, std::map<const Planet*, Edge*>> edges;

	// Ship name to id.
	std::map<std::string, Ship_ID> ships;

	// Route structure under construction.
	Galaxy* galaxy;
};

#endif

