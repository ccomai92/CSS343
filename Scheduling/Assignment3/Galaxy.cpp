
#include "Galaxy.h"

void Itinerary::print(Fleet& fleet) {
    int size = this->destinations.size();  
    int time_in_space = 0; 
    int departure_time = this->legs[size - 1].departure_time;
    int arrival_time = this->legs[size - 1].arrival_time;
    time_in_space += arrival_time - departure_time; 
    std::cout << fleet.name(this->legs[size - 1].id) << "\t"; 
    std::cout << this->origin->name << "\t"; 
    std::cout << departure_time << "\t"; 
    std::cout << this->destinations[size - 1]->name << "\t";
    std::cout << arrival_time << std::endl;
    for (int i = size - 1; i > 0; i--) {
        departure_time = this->legs[i - 1].departure_time;
        arrival_time = this->legs[i - 1].arrival_time;
        time_in_space += arrival_time - departure_time; 
        std::cout << fleet.name(this->legs[i].id) << "\t"; 
        std::cout << this->destinations[i]->name << "\t"; 
        std::cout << departure_time << "\t"; 
        std::cout << this->destinations[i - 1]->name << "\t";
        std::cout << arrival_time << std::endl;
    }

    std::cerr << "Arrival Time: " << this->legs[0].arrival_time << std::endl;

    int enroute_time = this->legs[0].arrival_time - this->legs[size - 1].departure_time;
    std::cerr << "Enroute Time: " << enroute_time << std::endl;

    
    std::cerr << "Time in Space: " << time_in_space << std::endl;
    std::cerr << std::endl; 
}

void Edge::dump(Galaxy* galaxy) {
    std::cerr << "Destination: " << this->destination->name << std::endl; 
    std::cerr << "Enroute Time: " << this->time << std::endl;
    for (auto& leg: this->departures) {
        std::cerr << "\t" << galaxy->fleet.name(leg.id) << "\t"
                    << leg.departure_time << "\t" 
                    << leg.arrival_time << std::endl; 
	}
}

