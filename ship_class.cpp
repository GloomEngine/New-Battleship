#ifndef SHIPS_STRUCT
#define SHIPS_STRUCT

#include <iostream>
#include <string>
#include <vector>
#include "battleship_class.cpp"
using namespace std;

class ship
{
    private:
        string name;
        int size;
        bool sunk;
        vector <int> hit;
        vector <int> position;
    
    public:

    ship()
    {
        name = "NO_NAME";
        size = 1;
        sunk = false;
    }

    ship(string ship_name, int ship_size, vector <int> spots)
    {
        name = ship_name;
        size = ship_size;
        sunk = false;
        position = spots;
    }

    bool Placement_check(ship *other)
    {
        return false;
    }
};

#endif