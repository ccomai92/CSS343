#ifndef SCHEDULING_EDGE_H
#define SCHEDULING_EDGE_H

#include <vector> 
#include "galaxy.h" 
#include "planet.h" 

class Edge {
public: 
    Edge(); 
    Edge(Planet* destination); 
    ~Edge(); 
    
    void add(Leg& leg) 
    void sort(); 
    void dump(Galaxy* galaxy); 
private: 
    Planet* destination; 
    std::vector<Leg> departures; 
}; 

#endif 
