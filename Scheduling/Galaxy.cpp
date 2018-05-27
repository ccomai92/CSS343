
#include "Galaxy.h"

void Itinerary::dump() {
    std::cout << this->origin->name << " "; 
    int size = this->destinations.size();  
    for (int i = size - 1; i >= 0; i--) {
        std::cout << this->legs[i].departure_time << " " 
                << this->legs[i].arrival_time << " ";
        std::cout << this->destinations[i]->name << " ";
    }
    std::cout << std::endl; 
}