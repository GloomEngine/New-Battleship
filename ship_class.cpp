#ifndef SHIPS_STRUCT
#define SHIPS_STRUCT

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "battleship_class.cpp"
using namespace std;

class ship
{
private:
    string name;
    int size;
    bool sunk;
    vector<int> positions;

public:
    ship()
    {
        name = "NO_NAME";
        size = 0;
        sunk = false;
    }

    ship(string ship_name, int ship_size)
    {
        name = ship_name;
        size = ship_size;
        sunk = false;
    }

    void Set_Position(vector<int> spots)
    {
        positions = spots;
    }

    vector<int> Get_Position()
    {
        return positions;
    }

    int Get_Size()
    {
        return size;
    }

    bool Position_Check(int position)
    {
        if (find(positions.begin(), positions.end(), position) != positions.end())
            return true;

        return false;
    }

    bool Placement_Check(ship *other)
    {
        return false;
    }

    bool Placement_Check(int start, int finish)
    {
        vector<int> temp = positions;

        sort(temp.begin(), temp.end());

        //return true;
    }

    bool is_Sunk()
    {
        return sunk;
    }
};

#endif