#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class inventory
{
private:
	string itemArr[4]{ "Empty", "Shield", "Potion", "Gloves" };
	map<string, int> commandMap;
	vector<string> inventoryVec;

public:
	inventory(int invSize);

	bool CheckIntInRange(int value, int min, int max);

	void Help();

	void View(int num);

	void ShowAll();

	void Set(int index, int itemID);

	void SearchItems(string itemName);

	void Items();

	void Exit();

	void Clear();

	void ExecuteCommand(string commandArr[], int arrSize, string command, inventory& aInventory);
};

