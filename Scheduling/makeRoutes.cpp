#include <iostream>
#include <string> 

using namespace std; 

int main() {
    int time = 0; 

    // ship 1; 
    for (int i = 0; i < 10; i++) {
        cout << "Andromeda Ascendant" << "\t"; 
        cout << "Dagobah" << "\t"; 
        cout << time << "\t"; 
        cout << "Dantooine" << "\t"; 
        time += 32; 
        cout << time << endl; 
        time += 4; // layover 
        
        cout << "Andromeda Ascendant" << "\t"; 
        cout << "Dantooine" << "\t"; 
        cout << time << "\t"; 
        cout << "Alderaan" << "\t"; 
        time += 13; 
        cout << time << endl; 
        time += 4; // layover 
        
        cout << "Andromeda Ascendant" << "\t"; 
        cout << "Alderaan" << "\t"; 
        cout << time << "\t"; 
        cout << "Yavin" << "\t"; 
        time += 5; 
        cout << time << endl;  

        time += 4; // layover 
        cout << "Andromeda Ascendant" << "\t"; 
        cout << "Yavin" << "\t"; 
        cout << time << "\t"; 
        cout << "Alderaan" << "\t"; 
        time += 5; 
        cout << time << endl;  
        time += 4; // layover 
        
        cout << "Andromeda Ascendant" << "\t"; 
        cout << "Alderaan" << "\t"; 
        cout << time << "\t"; 
        cout << "Dantooine" << "\t"; 
        time += 13; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Andromeda Ascendant" << "\t"; 
        cout << "Dantooine" << "\t"; 
        cout << time << "\t"; 
        cout << "Dagobah" << "\t"; 
        time += 32; 
        cout << time << endl; 
        time += 4; 
    }

    // ship2 
    time = 0; 
    for (int i = 0; i < 10; i++) {
        cout << "USSC Discovery One" << "\t"; 
        cout << "Gamor" << "\t"; 
        cout << time << "\t"; 
        cout << "Tatooine" << "\t"; 
        time += 40; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "USSC Discovery One" << "\t"; 
        cout << "Tatooine" << "\t"; 
        cout << time << "\t"; 
        cout << "Gamor" << "\t"; 
        time += 40; 
        cout << time << endl; 
        time += 4; // layover 
    }

    // ship3 
    time = 0; 
    for (int i = 0; i < 10; i++) {
        cout << "Galactica" << "\t"; 
        cout << "Endor" << "\t"; 
        cout << time << "\t"; 
        cout << "Sullust" << "\t"; 
        time += 19; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Galactica" << "\t"; 
        cout << "Sullust" << "\t"; 
        cout << time << "\t"; 
        cout << "Hoth" << "\t"; 
        time += 22; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Galactica" << "\t"; 
        cout << "Hoth" << "\t"; 
        cout << time << "\t"; 
        cout << "Bespin" << "\t"; 
        time += 4; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Galactica" << "\t"; 
        cout << "Bespin" << "\t"; 
        cout << time << "\t"; 
        cout << "Hoth" << "\t"; 
        time += 4; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Galactica" << "\t"; 
        cout << "Hoth" << "\t"; 
        cout << time << "\t"; 
        cout << "Sullust" << "\t"; 
        time += 22; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Galactica" << "\t"; 
        cout << "Sullust" << "\t"; 
        cout << time << "\t"; 
        cout << "Endor" << "\t"; 
        time += 19; 
        cout << time << endl; 
        time += 4; // layover 
    }

    // ship 4 
    time = 0; 
    for (int i = 0; i < 20; i++) {
        cout << "Heart of Gold" << "\t"; 
        cout << "Corulag" << "\t"; 
        cout << time << "\t"; 
        cout << "Brentaal" << "\t"; 
        time += 2; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Heart of Gold" << "\t"; 
        cout << "Brentaal" << "\t"; 
        cout << time << "\t"; 
        cout << "Rinnal" << "\t"; 
        time += 5; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Heart of Gold" << "\t"; 
        cout << "Rinnal" << "\t"; 
        cout << time << "\t"; 
        cout << "Ralltiir" << "\t"; 
        time += 1; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Heart of Gold" << "\t"; 
        cout << "Ralltiir" << "\t"; 
        cout << time << "\t"; 
        cout << "Chandrila" << "\t"; 
        time += 4; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Heart of Gold" << "\t"; 
        cout << "Chandrila" << "\t"; 
        cout << time << "\t"; 
        cout << "Esseles" << "\t"; 
        time += 3; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Heart of Gold" << "\t"; 
        cout << "Esseles" << "\t"; 
        cout << time << "\t"; 
        cout << "Corulag" << "\t"; 
        time += 4; 
        cout << time << endl; 
        time += 4; // layover 
    }

    // ship5 
    time = 0; 
    for (int i = 0; i < 20; i++) {
        cout << "Millenium Falcon" << "\t"; 
        cout << "Kessel" << "\t"; 
        cout << time << "\t"; 
        cout << "Bakura" << "\t"; 
        time += 27; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Millenium Falcon" << "\t"; 
        cout << "Bakura" << "\t"; 
        cout << time << "\t"; 
        cout << "Kessel" << "\t"; 
        time += 27; 
        cout << time << endl; 
        time += 4; // layover 
    }

    // ship6 
    time = 0; 
    for (int i = 0; i < 20; i++) {
        cout << "Moya" << "\t"; 
        cout << "Mon Calamari" << "\t"; 
        cout << time << "\t"; 
        cout << "Corporate Sector" << "\t"; 
        time += 1; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Moya" << "\t"; 
        cout << "Corporate Sector" << "\t"; 
        cout << time << "\t"; 
        cout << "Hapes Cluster" << "\t"; 
        time += 7; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Moya" << "\t"; 
        cout << "Hapes Cluster" << "\t"; 
        cout << time << "\t"; 
        cout << "Kessel" << "\t"; 
        time += 12; 
        cout << time << endl; 
        time += 4; // layover

        cout << "Moya" << "\t"; 
        cout << "Kessel" << "\t"; 
        cout << time << "\t"; 
        cout << "Hapes Cluster" << "\t"; 
        time += 12; 
        cout << time << endl; 
        time += 4; // layover

        cout << "Moya" << "\t"; 
        cout << "Hapes Cluster" << "\t"; 
        cout << time << "\t"; 
        cout << "Corporate Sector" << "\t"; 
        time += 7; 
        cout << time << endl; 
        time += 4; // layover

        cout << "Moya" << "\t"; 
        cout << "Corporate Sector" << "\t"; 
        cout << time << "\t"; 
        cout << "Mon Calamari" << "\t"; 
        time += 1; 
        cout << time << endl; 
        time += 4; // layover 
    }

    // ship7 
    time = 0; 
    for (int i = 0; i < 10; i++) {
        cout << "NSEA Protector" << "\t"; 
        cout << "Corellia" << "\t"; 
        cout << time << "\t"; 
        cout << "Bespin" << "\t"; 
        time += 6; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "NSEA Protector" << "\t"; 
        cout << "Bespin" << "\t"; 
        cout << time << "\t"; 
        cout << "Alderaan" << "\t"; 
        time += 8; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "NSEA Protector" << "\t"; 
        cout << "Alderaan" << "\t"; 
        cout << time << "\t"; 
        cout << "Tatooine" << "\t"; 
        time += 7; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "NSEA Protector" << "\t"; 
        cout << "Tatooine" << "\t"; 
        cout << time << "\t"; 
        cout << "Corellia" << "\t"; 
        time += 4; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "NSEA Protector" << "\t"; 
        cout << "Corellia" << "\t"; 
        cout << time << "\t"; 
        cout << "Yaga Minor" << "\t"; 
        time += 12; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "NSEA Protector" << "\t"; 
        cout << "Yaga Minor" << "\t"; 
        cout << time << "\t"; 
        cout << "Corellia" << "\t"; 
        time += 12; 
        cout << time << endl; 
        time += 4; // layover

        cout << "NSEA Protector" << "\t"; 
        cout << "Corellia" << "\t"; 
        cout << time << "\t"; 
        cout << "Tatooine" << "\t"; 
        time += 4; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "NSEA Protector" << "\t"; 
        cout << "Tatooine" << "\t"; 
        cout << time << "\t"; 
        cout << "Alderaan" << "\t"; 
        time += 7; 
        cout << time << endl; 
        time += 4; // layover 
        
        cout << "NSEA Protector" << "\t"; 
        cout << "Alderaan" << "\t"; 
        cout << time << "\t"; 
        cout << "Bespin" << "\t"; 
        time += 8; 
        cout << time << endl; 
        time += 4; // layover

        cout << "NSEA Protector" << "\t"; 
        cout << "Bespin" << "\t"; 
        cout << time << "\t"; 
        cout << "Corellia" << "\t"; 
        time += 6; 
        cout << time << endl; 
        time += 4; // layover 
    }

    // ship8
    time = 0; 
    for (int i = 0; i < 10; i++) {
        cout << "Red Dwarf" << "\t"; 
        cout << "Corellia" << "\t"; 
        cout << time << "\t"; 
        cout << "Coruscant" << "\t"; 
        time += 4; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Red Dwarf" << "\t"; 
        cout << "Coruscant" << "\t"; 
        cout << time << "\t"; 
        cout << "Mon Calamari" << "\t"; 
        time += 13; 
        cout << time << endl; 
        time += 4; // layover

        cout << "Red Dwarf" << "\t"; 
        cout << "Mon Calamari" << "\t"; 
        cout << time << "\t"; 
        cout << "Coruscant" << "\t"; 
        time += 13; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Red Dwarf" << "\t"; 
        cout << "Coruscant" << "\t"; 
        cout << time << "\t"; 
        cout << "Corulag" << "\t"; 
        time += 6; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Red Dwarf" << "\t"; 
        cout << "Corulag" << "\t"; 
        cout << time << "\t"; 
        cout << "Coruscant" << "\t"; 
        time += 6; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Red Dwarf" << "\t"; 
        cout << "Coruscant" << "\t"; 
        cout << time << "\t"; 
        cout << "Mon Calamari" << "\t"; 
        time += 13; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Red Dwarf" << "\t"; 
        cout << "Mon Calamari" << "\t"; 
        cout << time << "\t"; 
        cout << "Coruscant" << "\t"; 
        time += 13; 
        cout << time << endl; 
        time += 4; // layover

        cout << "Red Dwarf" << "\t"; 
        cout << "Coruscant" << "\t"; 
        cout << time << "\t"; 
        cout << "Corellia" << "\t"; 
        time += 4; 
        cout << time << endl; 
        time += 4; // layover 
    }

    // ship9 
    time = 0; 
    for (int i = 0; i < 10; i++) {
        cout << "Serenity" << "\t"; 
        cout << "Yaga Minor" << "\t"; 
        cout << time << "\t"; 
        cout << "Kashyyyk" << "\t"; 
        time += 53; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "Serenity" << "\t"; 
        cout << "Kashyyyk" << "\t"; 
        cout << time << "\t"; 
        cout << "Yaga Minor" << "\t"; 
        time += 53; 
        cout << time << endl; 
        time += 4; // layover 
    }

    // ship10 
    time = 0; 
    for (int i = 0; i < 10; i++) {
        cout << "USS Enterprise" << "\t"; 
        cout << "Yaga Minor" << "\t"; 
        cout << time << "\t"; 
        cout << "Wayland" << "\t"; 
        time += 30; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "USS Enterprise" << "\t"; 
        cout << "Wayland" << "\t"; 
        cout << time << "\t"; 
        cout << "Myrkr" << "\t"; 
        time += 21; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "USS Enterprise" << "\t"; 
        cout << "Myrkr" << "\t"; 
        cout << time << "\t"; 
        cout << "Wayland" << "\t"; 
        time += 21; 
        cout << time << endl; 
        time += 4; // layover 

        cout << "USS Enterprise" << "\t"; 
        cout << "Wayland" << "\t"; 
        cout << time << "\t"; 
        cout << "Yaga Minor" << "\t"; 
        time += 30; 
        cout << time << endl; 
        time += 4; // layover 
    }

    return 0; 
}