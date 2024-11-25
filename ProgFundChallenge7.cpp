// ProgFundChallenge7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct weapons {
    string itemName;
    string itemType;
    int price;
    int damage;
    string characterType;
};

vector<weapons> MakeVector()
{
    weapons greatsword{ "Great Sword", "Sword", 40, 100, "Knight" };
    weapons scimitar{ "Scimitar", "Sword", 35, 75, "Knight" };
    weapons dagger{ "Dagger", "Sword", 10, 35, "Knight" };
    weapons longbow{ "Longbow", "Bow", 20, 55, "Archer" };
    weapons crossbow{ "Crossbow", "Bow", 40, 100, "Archer" };
    weapons rustyspear{ "Rusty Spear", "Spear", 10, 35, "Spearman" };
    weapons ironspear{ "Iron Spear", "Spear", 20, 65, "Spearman" };

    vector<weapons> allWeapons{ greatsword, scimitar, dagger, longbow, crossbow, rustyspear, ironspear };
    return allWeapons;
}

void PrintWelcome(string names[], int arrSize)
{
    cout << "\n>> Welcome " << names[0] << ", " << names[1] << " and " << names[2] << " to the shop!";
    cout << "\n>> You currently have 100 coins. You can buy the following items: ";
    cout << "\n>> 1. Great Sword [40 coins , 100 damage]\n>> 2. Scimitar [35 coins , 75 damage]\n>> 3. Dagger [10 coins , 35 damage]\n>> 4. Longbow [20 coins , 55 damage]\n>> 5. Crossbow [40 coins , 100 damage]\n>> 6. Rusty spear [10 coins , 35 damage]\n>> 7. Iron spear [20 coins , 65 damage]";
}

bool BuyCheck(int choice, int coins, vector<int> takenWeapons, vector<weapons> weapons, int player)
{
    int overlap = count(takenWeapons.begin(), takenWeapons.end(), (choice - 1));

    if (choice < 1 || choice > 7) {
        cerr << "\n[!] ERROR: Please choose a valid item number.";
        cin.clear();
        cin.ignore(256, '\n');
        return false;
    }
    if (overlap > 0) {
       cerr << "\n[!] ERROR: This weapon is unavailable as it has already been purchased.";
       cin.clear();
       cin.ignore(256, '\n');
       return false;
    }
    if (coins < weapons.at(choice - 1).price) {
       cerr << "\n[!] ERROR: Not enough coins, the " << weapons.at(choice - 1).itemName << " is " << weapons.at(choice - 1).price << " coins and there are only " << coins << " available for use!";
       cin.clear();
       cin.ignore(256, '\n');
       return false;
    }
    else {
        return true;
    }
}

void BuyItem(vector<weapons> weapons, vector<int>& takenWeapons, string allPlayers[], int arrSize, int player, int& coins)
{
    bool weaponBought = false;
    int choice;

    while (weaponBought == false)
    {
        cout << "\n\nPlayer " << player + 1 << ", please enter a weapon to buy: ";
        if (!(cin >> choice))
        {
            cerr << "\n[!] ERROR: Not a number!";
            cin.clear();
            cin.ignore(256, '\n');
        }
        else if (BuyCheck(choice, coins, takenWeapons, weapons, player)) {
            weaponBought = true;
        }
    }

    takenWeapons.push_back(choice - 1);
    cout << "\n>> " << allPlayers[player] << " bought a " << weapons.at(choice - 1).itemName << " for " << weapons.at(choice - 1).price << " coins. The party now has " << (coins -= weapons.at(choice - 1).price) << " coins.";
}

void GameLoop()
{
    // Creates the string variables for the players names
    string player1, player2, player3;

    //Adds them into an array
    string namesArr[3] = { player1, player2, player3 };

    //For loop that checks the validity of each players name
    for (int i = 0; i < 3; i++)
    {
        //Condition for while loop
        bool namesValid = false;
        //Num of alphanumeric characters in name
        int alphas = 0;

        while (namesValid == false)
        {
            //Prompt for input
            cout << "Enter player #" << i + 1 << "'s name: ";
            //Stores input in appropriate variable
            cin >> namesArr[i];

            //Checks all characters to be alphanumeric
            for (char& c : namesArr[i]) {
                if (isalpha(c)) { alphas++; }
            }

            //If the amount of alphanumeric characters == length of the name, the name is valid
            if (alphas == namesArr[i].length()) { namesValid = true; }
            //If not print out an error and reset alphas
            else { cerr << "[!] ERROR: Only input alphabetical characters!\n"; alphas = 0; }
        }
    }

    vector<int> takenWeapons;
    vector<weapons> allWeapons = MakeVector();
    bool checkComp = false;
    

    while (checkComp == false)
    {
        int coins = 100;
        PrintWelcome(namesArr, 3);

        for (int i = 0; i < 3; i++)
        {
            BuyItem(allWeapons, takenWeapons, namesArr, 3, i, coins);
        }

        bool choiceValid = false;
        string finalChoice;
        while (choiceValid == false)
        {
            cout << "\n\nAre you happy with your selection? (yes/no): "; 
            cin >> finalChoice;

            if (finalChoice == "yes" || finalChoice == "no")
            {
                choiceValid = true;
            }
            else {
                cerr << "\n[!] ERROR: Please enter 'yes' or 'no'.";
            }
        }

        if (finalChoice == "no") {
            checkComp = false;
            takenWeapons.clear();
            cout << "\n---------------------------------------------------------------------\n";
        }
        else {
            checkComp = true;
        }
    }

    cout << "\n\nThe party: ";
    for (int i = 0; i < 3; i++)
    {
        cout << "\nPlayer " << i + 1 << "(" << namesArr[i] << "), Role: " << allWeapons.at(takenWeapons.at(i)).characterType << ", Weapon: " << allWeapons.at(takenWeapons.at(i)).itemName << ", Damage: " << allWeapons.at(takenWeapons.at(i)).damage << ".";
    }
    cout << "\nYou are situated in a forest. A monster appears...";
}

int main()
{
    GameLoop();

    return 0;
}