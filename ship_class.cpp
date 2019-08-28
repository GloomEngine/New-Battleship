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

    ship(string ship_name, int ship_size)
    {
        name = ship_name;
        size = ship_size;
        sunk = false;
        position_ship();
    }

    void position_ship()
    {
        cout << "Here: Press any Key";
        getchar();
    }
};

#endif