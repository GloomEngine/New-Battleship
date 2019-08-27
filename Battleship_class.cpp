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

        cin.ignore();
        cout << endl;
        PrintCenteredText("Press any key when ready");
        getchar();

        system("cls");
    }

    string GetPlayerName()
    {return player_name;}

    void PositionShips()
    {
        Print_Board();
        system("pause");
    }

    void Print_Board()
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
                    {
                        /*if(!temp.empty() && convert(x, y) == temp[0].first)
                        {
                            cout << temp[0].second;
                            temp.erase(temp.begin());
                        }
                        else*/
                            cout << " ";                      
                    }
					else { cout << "\t|"; }
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

