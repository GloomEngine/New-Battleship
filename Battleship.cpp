#include <iostream>
#include <string>
#include <vector>
#include "battleship_class.cpp"
using namespace std;

int main(void)
{
    int player_count = 2;
    vector<battleship> player;

    /*cout << "Enter Player count (2-5): ";
    for(cin>>player_count; player_count<2; cin>>player_count)
        cout << "Error: must be between 2 and 5";*/

    for (int x = 0; x < player_count; x++)
        player.push_back(battleship());

    do
    {
        //Only call class functions in here
        return 0;
    } while (1); // Until game is over
}