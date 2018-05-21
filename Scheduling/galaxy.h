/* Reference: 
*    https://courses.washington.edu/css343/bernstein/2018-q2/assignment-03/galaxy.h
*   "galaxy.h" is modified by Kris Kwon 
*/

#ifndef SCHEDULING_GALAXY_H
#define SCHEDULING_GALAXY_H

#include <string> 
#include <map> 

class Galaxy {
public: 
    Galaxy(); 
    ~Galaxy(); 
    
    void add(Planet* planet);
    void reset();
    void search(); 
private: 
    Fleet fleet; 
    std::map<std::string, Planet*> planets;
     
    void dump(); 
    void dump_routes(Planet* origin); 
}; 
#endif
