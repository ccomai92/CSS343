#include "stdafx.h"
#include "Galaxy.h"


Galaxy::Galaxy() {
}


Galaxy::~Galaxy() {
}

void Itinerary::print(Fleet& fleet, std::ostream& out) {
	
}

Planet * Planet::search(PriorityQueue<Planet, int(*)(Planet*, Planet*)>& queue) {
	return nullptr;
}

Itinerary * Planet::make_itinerary(Planet * destination) {
	return nullptr;
}

void Planet::relax_neighbors(PriorityQueue<Planet, int(*)(Planet*, Planet*)>& queue) {
}

void Galaxy::search() {
}
