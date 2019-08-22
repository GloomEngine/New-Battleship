#ifndef BATTLESHIP_CLASS
#define BATTLESHIP_CLASS

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class battleship
{

private:
    string player_name;

public:

    battleship()
    {
        SetPlayerName();
        PositionShips();
    }

    void SetPlayerName()
    {
        cout << "Enter Player name: ";
        cin >> player_name; //TODO: Add error checking for name
        system("cls");
        PrintCenteredText();
    }

    string GetPlayerName()
    {return player_name;}

    void PositionShips()
    {
        
    }

    void PrintCenteredText()
    {
        string message = "Players look away while " + player_name + " enters their ships";
        int pad = (80 - message.size())/2;
        if(pad > 0)
            cout << setw(pad+message.size()) << message; 
        getchar();

    }
};

#endif

