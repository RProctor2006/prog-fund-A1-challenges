// ProgFundChallenge2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string playerName;
    string username;
    string clanTag;
    unsigned int xpPoints;

    cout << "-----------------------------------------------------------------------------------------\n";
    cout << "Welcome! Please tell me your name: ";
    cin >> playerName;
    
    cout << "\nWhat is your username?: ";
    cin >> username;

    cout << "\nWhat is your clan tag?: ";
    cin >> clanTag;

    cout << "\nHow much XP do you have?: ";
    cin >> xpPoints;

    cout << "\n\n>> Your name is " << playerName << " and your in-game name is [" << clanTag << "] " << username << ".";
    cout << "\n>> You have " << xpPoints << " experience points.";
}
