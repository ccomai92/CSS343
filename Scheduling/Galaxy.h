// galaxy.h
//
// Declarations for a graph representing Old Republic Spaceways' route
// structure.  Nodes are system planets edges hold the list of ships'
// legs traveling from the origin to destination planet.
//
// Additional fields are defined to allow implementation of Dijkstra's
// algorithm to find the minimum cost (earliest arrival time) between
// pairs of planets.
//
// Copyright 2013, 2018 Systems Deployment, LLC
// Author: Morris Bernstein (morris@systems-deployment.com)
// Modified by Kris Kwon for CSS 343 assignment 3 

#ifndef GALAXY_H
#define GALAXY_H

#include <climits>
#include <iostream>
#include <ostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cassert>

#include "priority.h"

typedef int Time;
const Time MAX_TIME = INT_MAX;
const Time TURNAROUND_TIME = 4;
const Time TRANSFER_TIME = 4;

typedef int Ship_ID;

class Planet;
class Galaxy;

// Class Fleet maps internal ship ID to the ship's name .
class Fleet {
public:
	Fleet() {}
	~Fleet() {}
	Ship_ID add(const std::string& name) { 
		names.push_back(name); 
		return names.size() - 1; 
	}

	const std::string& name(Ship_ID id) const { 
		return names[id]; 
	}

private:
	std::vector<std::string> names;
};


// Class Leg represents a single leg of an itinerary, consisting of a
// ship ID, departure time, and arrival time.  Legs are associated
// with an edge between two planets (vertices) in the galaxy map.
//
// A pair of legs may be compared to find the earliest arrival time.
class Leg {
public:
	Leg() : id(-1), departure_time(MAX_TIME), arrival_time(MAX_TIME) {}
	Leg(Ship_ID id, Time departure_time, Time arrival_time)
		: id(id), departure_time(departure_time), arrival_time(arrival_time) {
	}

	// Return negative, zero, or positive for left leg arriving before,
	// same time, or after the right leg (respectively
	static int compare(const Leg& left, const Leg& right) {
		return left.arrival_time - right.arrival_time;
	}

	static bool less_than(const Leg& left, const Leg& right) {
		return compare(left, right) < 0;
	}

	Ship_ID id;
	Time departure_time;
	Time arrival_time;
};


// Class Itinerary is a sequence of legs with a parallel sequence of
// destinaion planets. i.e. destinations[i] is the destination of
// leg[i].
class Itinerary {
public:
	Itinerary(Planet* origin) : origin(origin) {}
	void print(Fleet& fleet); 

	Planet* origin;
	std::vector<Planet*> destinations;
	std::vector<Leg> legs;
};


// Class Edge is a single edge in the route graph.  It consists of a
// destination planet and a sequence of legs departing from the origin
// planet (vertex) to the destination planet.
class Edge {
public:
	Edge(Planet* destination, Time& time) : destination(destination), time(time) {}

	void add(Leg leg) { 
		departures.push_back(leg);
	}

	// sort(): sort the legs of this edge by arrival time to the
	// destination planet.
	void sort() {
		std::sort(this->departures.begin(), this->departures.end(), Leg::less_than); 
	}

	void dump(Galaxy* galaxy) {
		
	}

	Time time; 
	Planet* destination;
	std::vector<Leg> departures;
};


//  Class Planet is a node in the route graph.  It contains a sequence
//  of edges plus additional fields to allow implementation of
//  Dijkstra's shortest-path algorithm.
class Planet {
public:
	Planet(const std::string& name): name(name), best_leg(Leg{}),
									 predecessor(nullptr), priority(0) {}
	void add(Edge* e) {
		edges.push_back(e);
	}

	// reset() clears the fields set by Dijkstra's algorithm so the
	// algorithm may be re-run with a different origin planet.
	void reset() {
		predecessor = nullptr; 
		best_leg = Leg{};
		this->priority = 0; 
	}

	// search() computes the shortest path from the Planet to each of the
	// other planets and returns the furthest planet by travel time.
	Planet* search(PriorityQueue<Planet, int(*)(Planet*, Planet*)>& queue) {
		this->best_leg = Leg(-1, 0, 0);
		Planet* furthest = this; 
		queue.reduce(this); 
		while(!queue.empty()) {
			Planet* current = queue.pop(); 
			//assert(current->arrival_time() != MAX_TIME); 
			if (current->arrival_time() > furthest->arrival_time()) {
				furthest = current; 
				//std::cerr << current->name << std::endl; 
				//std::cerr << current->arrival_time() << std::endl; 
			} 
			current->relax_neighbors(queue);
		}
		return furthest; 
	}

	// make_itinerary() builds the itinerary with the earliest arrival
	// time from this planet to the given destination planet.
	Itinerary* make_itinerary(Planet* destination) {
		Itinerary* result = new Itinerary(this); 
		Planet* current = destination; 
		Planet* predecessor = destination->predecessor; 
		while (predecessor != nullptr) {
			result->destinations.push_back(current);
			result->legs.push_back(current->best_leg);
			current = predecessor; 
			predecessor = current->predecessor; 
		}
		return result; 
	}

	// arrival_time() is the time to arrive at this planet from the
	// origin planet that was used to compute the most recent search().
	Time arrival_time() const {
		return best_leg.arrival_time; 
	}

	// Debug-friendly output.
	void dump() { //Galaxy* galaxy
		std::cerr << this->name <<  ": " << std::endl; 
		int size = this->edges.size(); 
		std::cerr << size << std::endl; 
		for (int i = 0; i < size; i++) {
			std::cerr << this->edges[i]->destination->name << std::endl; 
		}
	}

	// Functions for priority queue:
	int get_priority() {
		return this->priority; 
	}

	void set_priority(int new_priority) {
		this->priority = new_priority; 
	}

	Planet* getPredecessor() {
		return this->predecessor;
	}

	const Leg& getLeg() {
		return this->best_leg; 
	}

	static int compare(Planet* left, Planet* right) {
		return Leg::compare(left->best_leg, right->best_leg);
	}

	const std::string name;

private:
	// relax_neighbors(): for each neighboring planet of this planet,
	// determine if the route to the neighbor via this planet is faster
	// than the previously-recorded travel time to the neighbor.
	void relax_neighbors(PriorityQueue<Planet, int(*)(Planet*, Planet*)>& queue) {
		Time min_next_departure = this->best_leg.arrival_time + TRANSFER_TIME; 
		for (auto& edge: this->edges) {
			Planet* destination = edge->destination; 
			edge->sort(); 
			int size = edge->departures.size();
			Leg bestLeg; 
			for (int i = 0; i < size; i++) {
				Leg current = edge->departures[i];
				if (current.departure_time >= min_next_departure
					&& Leg::less_than(current, bestLeg)) {
					bestLeg = current; 
				}
			} 
			if (Leg::less_than(bestLeg, destination->best_leg)) {
				destination->predecessor = this; 
				destination->best_leg = bestLeg;
				queue.reduce(destination); 
			}  
		}
	}

	// edges shows the connections between this planet and it's
	// neighbors.  See class Edge.
	std::vector<Edge*> edges;

	// For Dijkstra's algorithm:
	Planet* predecessor;
	Leg best_leg;
	int priority;
};


// Class galaxy holds the graph of Old Republic Spaceways' route
// structure, consisting of a sequence of planets (vertices).  The
// graph is constructed by adding new planets to the Galaxy object and
// adding edges to the planet objects.
class Galaxy {
public:
	Galaxy(): planets(), fleet() {}
	~Galaxy() {}

	void add(Planet* planet) {
		this->planets.push_back(planet);
	}

	void reset() { 
		for (auto planet : this->planets) {
			planet->reset();
		}
	}

	// For each planet, apply Dijkstra's algorithm to find the minimum
	// travel time to the other planets.  Print the itinerary to the
	// furthest planet. Terminate with EXIT_FAILURE if the graph is not
	// strongly connnected (you can't get there from here).  Finally,
	// print the diameter of the galaxy and its itinerary.
	void search() {
		int size = this->planets.size(); 

		for (int i = 0; i < size; i++) {
			PriorityQueue<Planet, int(*)(Planet*, Planet*)> priorityQ(Planet::compare); 
			for (int i = 0; i < size; i++) {
				priorityQ.push_back(this->planets[i]);  
			}
			Planet* furthest = this->planets[i]->search(priorityQ); // passing priority queue 
			//this->dump_routes(this->planets[i], furthest, std::cerr); 
			Itinerary* result = this->planets[i]->make_itinerary(furthest); 
			result->print(this->fleet); 
			this->reset(); 
		}
	}

	void dump() {
		int size = this->planets.size(); 
		std::cerr << "size " << size << std::endl; 
		for (int i = 0; i < size; i++) {
			Planet* temp = this->planets[i]; 
			temp->dump(); 
			std::cerr << std::endl; 
		}
	}

	void dump_routes(Planet* origin, Planet* destination, std::ostream& out = std::cerr) {
		
	}

	Fleet fleet;
	std::vector<Planet*> planets;
};

#endif
