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
    vector<ship> ships;
    vector<int> miss;

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

        while (name.empty() || !isalpha(name.at(0)))
        {
            system("cls");
            if (name.empty())
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
    {
        return player_name;
    }

    void Add_Ships()
    {
        string default_names[5] = {"Carrier", "Battleship", "Destroyer", "Submarine", "Patrol Boat"};
        int default_sizes[5] = {5, 4, 3, 3, 2};

        for (int x = 0; x < 5; x++)
        {
            //TODO add ship placement function (return vector with positions)
            ships.push_back(ship(default_names[x], default_sizes[x]));
            Position_Ship(ships.back());
        }

        //TODO Add custom ship compatablity
    }

    void Print_Board(ship sh)
    {
        vector<int> taken = sh.Get_Position();
        sort(taken.begin(), taken.end());

        cout << "\n\n     1   2   3   4   5   6   7   8   9   0\n";

        for (int x = 0; x < 11; x++)
        {
            for (int y = 0; y < 10; y++)
            {
                if (y == 0)
                {
                    cout << "    ---";
                }
                else
                {
                    cout << " ---";
                }

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
                        if (!taken.empty() && convert(x, y) == taken[0])
                        {
                            cout << "X";
                            taken.erase(taken.begin());
                        }
                        else
                            cout << " ";
                    }
                    else
                    {
                        cout << "\t|";
                    }
                }
            }
            cout << endl;
        }
    }

    void PrintCenteredText(string message)
    {
        int pad = (120 - message.size()) / 2;
        if (pad > 0)
            cout << setw(pad + message.size()) << message;
        else
            cout << "Error: Pad too large";
    }

    char Find_Direction(ship sh)
    {
        string dir;

        if (sh.Placement_Check(sh.Get_Position().at(0), sh.Get_Position().at(0) + sh.Get_Size()))
        {
            dir += 'r';
        }

        if (sh.Placement_Check(sh.Get_Position().at(0), sh.Get_Position().at(0) - sh.Get_Size()))
        {
            dir += 'l';
        }

        if (sh.Placement_Check(sh.Get_Position().at(0), sh.Get_Position().at(0) + (sh.Get_Size() * 10)))
        {
            dir += 'd';
        }

        if (sh.Placement_Check(sh.Get_Position().at(0), sh.Get_Position().at(0) - (sh.Get_Size() * 10)))
        {
            dir += 'u';
        }

        if (dir.empty())
            return '\0';

        string direction;

        cout << " Enter Direction (" << dir << "): ";
        cin >> direction;

        while (dir.find(direction) == string::npos || direction.size() > 2)
        {
            system("cls");
            Print_Board(sh);
            cout << "\n Error: Must enter given direction\n";
            cout << " Enter Direction (" << dir << "): ";
            cin.ignore();
            cin >> direction;
        }

        return direction.at(0);
    }

    void Position_Ship(ship sh)
    {
        string start;
        vector<int> ship_position;

        Print_Board(sh);

        cout << "Please enter a starting position (Ex: A1): ";
        getline(cin, start);

        while (bad_ship_placement(start))
        {
            system("cls");
            cout << player_name << " enter your ships\n";
            Print_Board(sh);
            error_codes(bad_ship_placement(start));
            cout << "\n Enter starting position (Ex: A1): ";
            getline(cin, start);
        }
        int position = convert(start);

        ship_position.push_back(position);

        sh.Set_Position(ship_position);

        system("cls");

        Print_Board(sh);

        Find_Direction(sh);
    }

    int convert(string position)
    {
        int number = stoi(position.substr(1));

        if (number == 0)
            number = 10;

        return convert(toupper(position.at(0)) - 65, number - 1);
    }

    int convert(int row, int col)
    {
        if (row == 0)
            return col;

        if (col == 0)
            return row * 10;

        return (row * 10) + col;
    }

    int *convert(int position)
    {
        int *pos = new int[2];

        pos[1] = (position % 10);
        pos[0] = (position / 10) % 10;

        return pos;
    }

    int bad_ship_placement(string position)
    {
        if (position.length() < 2 || position.length() > 3)
            return 1;

        char letter = position.at(0);

        if (!isalpha(letter))
            return 2;

        letter = toupper(letter);

        for (int x = 1; x < position.length(); x++)
        {
            if (!isdigit(position.at(x)))
                return 3;
        }

        int number = stoi(position.substr(1));

        if (letter < 'A' || letter > 'J')
            return 4;

        if (number < 0 || number > 10)
            return 5;

        if (number == 0)
            number = 10;

        int temp = convert(toupper(letter) - 65, number - 1);

        for (auto x : ships)
        {
            if (x.Position_Check(temp))
                return 6;
        }
        return 0;
    }

    void error_codes(int error)
    {
        switch (error)
        {
        case 1:
            cout << " Error: Expecting only a letter and number up to 10";
            break;
        case 2:
            cout << " Error: Expected a letter followed by a number";
            break;
        case 3:
            cout << "Error: Number Must be between 0 and 10";
            break;
        case 4:
            cout << " Error: Letter must be between A and J";
            break;
        case 5:
            cout << " Error: Number must be between 1 and 10";
            break;
        case 6:
            cout << " Error: Position collides with another ship: ";
            break;
        default:
            return;
        }
        return;
    }
};

#endif
