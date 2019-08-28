#ifndef SHIPS_STRUCT
#define SHIPS_STRUCT

#include <string>
#include <vector>

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
        name = "";
        size = 0;
        sunk = false;
    }

    ship(string ship_name, int ship_size)
    {
        name = ship_name;
        size = ship_size;
        sunk = false;
    }
};

#endif