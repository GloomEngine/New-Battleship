#ifndef BATTLESHIP_CLASS
#define BATTLESHIP_CLASS

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "ship_class.cpp"
using namespace std;

class battleship
{

private: 
    string player_name;
    vector <ship> ships;
    vector <int> miss;

public:

    battleship()
    {
        SetPlayerName();
        Add_Ships();
    }

    void SetPlayerName()
    {
        string name;

        cout << "Enter Player name: ";
        getline(cin, name);
        
        while(name.empty() || !isalpha(name.at(0)))
        {
            system("cls");
            if(name.empty())
            {
                cout << "Error: Name cannot be empty\n";
                cout << "Enter Player name: ";
            }

            else
            {
                cout << "Error: Name must start with a letter\n";
                cout << "Enter Player name: ";
            }
            getline(cin, name);
        }
        player_name = name;
        cout << endl;
        system("cls");

        string message = "Players look away while " + player_name + " enters their ships\n";
        PrintCenteredText(message);

        cout << endl;
        PrintCenteredText("Press any key when ready");
        getchar();

        system("cls");
    }

    string GetPlayerName()
    {return player_name;}

    void Add_Ships()
    {
        string default_names[5] = {"Carrier", "Battleship", "Destroyer", "Submarine", "Patrol Boat"};
        int default_sizes[5] = {5, 4, 3, 3, 2};

        for(int x = 0; x < 5; x++)
            ships.push_back(ship(default_names[x], default_sizes[x]));

        //TODO Add custom ship compatablity
    }

    void Print_Board(int modifier)
    {
        cout << "\n\n     1   2   3   4   5   6   7   8   9   0\n";

		for (int x = 0; x < 11; x++)
		{
			for (int y = 0; y < 10; y++)
			{
				if (y == 0) { cout << "    ---"; }
				else { cout << " ---"; }

				if (y == 9 && x != 0 && x != 10)
					cout << "\t|";
			}

			cout << endl;

			if (x < 10)
			{
				cout << ' ' << char(x + 65);

				for (int y = 0; y < 11; y++)
				{
					cout << " | ";

					if (y < 10)
                        cout << " ";                      
                    
					else
                        cout << "\t|";
				}
			}
            cout << endl;
        }
    }

    void PrintCenteredText(string message)
    {
        int pad = (120 - message.size())/2;
        if(pad > 0)
            cout << setw(pad+message.size()) << message;
        else
            cout << "Error: Pad too large";
    }
};

#endif

