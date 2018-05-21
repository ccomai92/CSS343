/* Reference: 
*       https://courses.washington.edu/css343/bernstein/2018-q2/assignment-03/galaxy.h
*       "planet.h" is modified by Kris Kwon 
*/

#ifndef SCHEDULING_PLANET_H
#define SCHEDULING_PLANET_H

#include <string> 
#include <vector> 
#include "galaxy.h" 
#include "edge.h" 
#include "priority.h" 

class Planet {
public: 
    Planet(); 
    Planet(const std::string& name);
    
    const std::string getName(); 
    void setIndex(int index); 
    int getIndex(); 
    
    void add(Edge* e);
    void reset(); 
    Planet* search(PriorityQueue<Planet, int (*)(Planet*, Planet*)>& queue); 
    Itinerary* make_itinerary(Planet* destination); 
    Time arrival_time() const;
    void dump(Galaxy* galaxy); 
    
    static int compare(Planet* left, Planet* right) {
        return Leg::compare(left->bestLeg, right->bestLeg); 
    }
  
private: 
    const std::string name; 
    std::vector<Edge*> edges; 

    // For Dijkstra
    Planet* predecessor;
    Leg bestLeg; 
    int priority;

    void relax_neighbors(PriorityQueue<Planet, int (*)(Planet*, Planet*)>& queue);   
}; 

#endif 
