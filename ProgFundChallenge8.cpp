// ProgFundChallenge8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

#include "inventory.h"

using namespace std;

inventory InitialiseInventory()
{
    int invSize;
    bool valid = false;

    while (valid == false)
    {
        cout << "- Please enter an inventory size: ";
        cin >> invSize;
        if (cin.fail() || invSize < 1 || invSize > 16) {
            cin.clear();
            cin.ignore(256, '\n');
            cerr << "[!] ERROR: Please enter a number between 1 and 16.\n";
        }
        else {
            valid = true;
        }
    }

    inventory aInventory = inventory(invSize);
    cout << ">> Initialised inventory with " << invSize << " slots.\n";
    cout << ">> Type ""help"" for a list of all commands.\n\n";

    return aInventory;
}

bool ValidCommand(string commandsArr[], int arrSize, string command)
{
    for (int i = 0; i < arrSize; i++)
    {
        if (command == commandsArr[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string commArr[8]{ "view", "show_all", "set", "search_item", "items", "exit", "help", "clear" };
    string command, item;
    int val1 = 0;
    int val2 = 0;

    bool comp = false;

    while (comp == false)
    {

        bool temp = false;

        inventory aInventory = InitialiseInventory();
        
        while (temp == false) {
            cout << "\n- ";
            cin >> command;
            if (command == "restart")
            {
                temp = true;
            }
            else if (ValidCommand)
            {
                aInventory.ExecuteCommand(commArr, 8, command, aInventory);
            }
            else {
                cin.clear();
                cin.ignore(256, '\n');
                cerr << "\n[!] ERROR: Not a valid command!";
            }
        }
        aInventory.Clear();
    }

    return 0;
}