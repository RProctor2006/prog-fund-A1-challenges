#include "inventory.h"

inventory::inventory(int invSize)
{
	commandMap["view"] = 0;
	commandMap["show_all"] = 1;
	commandMap["set"] = 2;
	commandMap["search_item"] = 3;
	commandMap["items"] = 4;
	commandMap["exit"] = 5;
	commandMap["help"] = 6;
	commandMap["clear"] = 7;

	for (int i = 0; i < invSize; i++)
	{
		inventoryVec.push_back(itemArr[0]);
	}
}

bool inventory::CheckIntInRange(int value, int min, int max)
{
	if (value < min || value > max) { return false; }
	else { return true; }
}

void inventory::Help()
{
	cout << "\n>> view <index>: Prints out details of the item specified by slot index\n";
	cout << ">> show_all: Shows all inventory slots and their details.\n";
	cout << ">> set <index> <itemid>: Sets slot specified by index to the item given.\n";
	cout << ">> search_item <str>: Searches the item list for any item with the given name.\n";
	cout << ">> items: Shows all items.\n";
	cout << ">> exit: Exits the tool.\n";
	cout << ">> restart: Restarts the session.\n";
	cout << ">> help: Shows this list of commands.\n";
	cout << ">> clear: Clears the inventory.\n";
}

void inventory::View(int num)
{
	cout << ">> Inventory slot " << num << " details:\n";
	cout << ">> Name: " << inventoryVec.at(num) << endl;
}

void inventory::ShowAll()
{
	cout << ">>Inventory:\n";
	
	for (int i = 0; i < inventoryVec.size(); i++)
	{
		cout << ">> - Slot " << i << ": " << inventoryVec.at(i) << endl;
	}
}

void inventory::Set(int index, int itemID)
{
	inventoryVec.at(index) = itemArr[itemID];
}

bool CaseInsensitiveCharCompare(char a, char b)
{
	return tolower(a) == tolower(b);
}

void inventory::SearchItems(string itemName)
{
	
	vector<int> inventoryIndexes;

	for (int i = 0; i < inventoryVec.size(); i++)
	{
		auto c = search(inventoryVec.at(i).begin(), inventoryVec.at(i).end(), itemName.begin(), itemName.end(), CaseInsensitiveCharCompare);

		if (c != inventoryVec.at(i).end()) { inventoryIndexes.push_back(i); }
	}

	if (inventoryIndexes.size() == 0)
	{
		cout << ">> [!] There are no items containing any of those characters\n";
	}
	else {
		cout << ">> Search results:\n";
		
		for (int i = 0; i < inventoryIndexes.size(); i++)
		{
			cout << ">> - Item index " << inventoryIndexes.at(i) << ": " << inventoryVec.at(inventoryIndexes.at(i)) << endl;
		}
	}
}

void inventory::Items()
{
	cout << ">> 0: Empty\n>> 1: Shield\n>> 2: Potion\n>> 3: Gloves\n";
}

void inventory::Exit()
{
	cout << ">> Exiting.\n\n";
	exit(0);
}

void inventory::Clear()
{
	inventoryVec.clear();
	cout << ">> Cleared inventory\n";
}

void inventory::ExecuteCommand(string commandArr[], int arrSize, string command, inventory& aInventory)
{
	int val1;
	int val2;

	string item;

	switch (commandMap[command]) {
	case 0:
		cin >> val1;
		if (CheckIntInRange(val1, 0, inventoryVec.size() - 1) == false) { cerr << "[!] ERROR: " << val1 << " is not a number between 0 and " << inventoryVec.size() - 1; break; }

		View(val1);

		break;
	case 1:
		ShowAll();

		break;
	case 2:
		cin >> val1 >> val2;
		if (CheckIntInRange(val1, 0, inventoryVec.size() - 1) == false) { cerr << "[!] ERROR: " << val1 << " is not a number between 0 and " << inventoryVec.size() - 1; break; }
		if (CheckIntInRange(val2, 0, 3) == false) { cerr << "[!] ERROR: " << val2 << " is not a number between 0 and 3"; break; }

		Set(val1, val2);

		break;
	case 3:
		cin >> item;
		SearchItems(item);

		break;
	case 4:
		Items();

		break;
	case 5:
		Exit();

		break;
	case 6:
		Help();

		break;
	case 7:
		Clear();

		break;
	}
}
