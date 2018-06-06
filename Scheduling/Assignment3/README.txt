README.txt 


Gihwan Kwon (Kris) 
CSS343 - Data Structures, Algorithms, Discrete Mathematics 2
Assignment 3 - Scheduling
--------------------------------------------------------------

This program is given with conduits.txt which defines the galaxy
and routes.txt which defines the spaceships schedules. This 
program search all longest-shortest path that passenger can go from 
every planet. The output is all longest-shortest path from every 
planet in same format as input routes.txt file in itinerary.txt. 
The log_file.txt contains galaxy format with schedules, arrival time,
total enroute time, and time in space.  

Input Format: 
'#' in the first column or blank line will be ignored.
conduits.txt
    Planet name \t Planet name \t Time 

    e.g. 
    Alderaan	Sullust	213
    Alderaan	Tatooine	7
    Alderaan	Yavin	5
    Bespin	Corellia	6
    Bespin	Coruscant	158
    Bespin	Dagobah	27

routes.txt 
    Ship name \t Departure planet \t Deaprture time \t Destination Planet \t Arrival time 

    e.g. 
    Andromeda Ascendant	Alderaan	567	Dantooine	580
    Andromeda Ascendant	Dantooine	584	Dagobah	616
    USSC Discovery One	Gamorr	0	Tatooine	40
    USSC Discovery One	Tatooine	44	Gamorr	84