#! /bin/bash
# run scheduling program with inputs and directing outputs to files. 
#-------------------------------------------------------------------

./scheduling conduits.txt routes.txt > itinerary.txt 2> log_file.txt
