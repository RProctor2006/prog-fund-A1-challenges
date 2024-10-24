// ProgFundChallenge4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

bool tryAgain = false;

// Function that checks if the user input has any characters in it
bool ValidTest(string input)
{
	if (input.empty())
	{
		return false;
	}
	else {
		return true;
	}
}

// Function that prints out ascii lines dependant on the amount of characters, made purely for ease of access
void PrintLines(int charNum)
{
	for (int i = 1; i <= charNum; i++)
	{
		cout << "+=-=-=";
	}

	//Ends off the line with a '+'
	cout << "+\n";
}

int main()
{
	string userInput;
	
	// The getline function in this case reads the users input, and stores it in the 'userInput' variable declared above
	if (tryAgain)
	{
		// Uses 'cerr' to print out an error message
		cerr << "\n[!] ERROR: Invalid input , nothing entered. Try again: ";
	}
	else {
		cout << "\nPlease enter a sentence, type 'exit' to exit the program: ";
	}

	// Getline is also ideal in this case as it reads spaces between words
	getline(cin, userInput);

	// Here I used the '.length()' function in order to find out how many characters are in the players input
	int numOfChars = userInput.length();

	// Just an easy way for the user to exit the program
	if (userInput == "exit")
	{
		exit(0);
	}

	// This while loop is the main loop for the program
	while (userInput != "exit")
	{
		// Checks if the players input is valid using the function I made
		if (ValidTest(userInput))
		{
			cout << "\n";
			tryAgain = false;

			// Prints out the top ASCII line via the function I made
			PrintLines(numOfChars);

			// Goes through every character and adds the necessary characters and spaces
			for (char& c : userInput)
			{
				cout << "|  " << c << "  ";
			}

			// After the for loop has gone through all the characters, this closes off the line with a '|'
			cout << "|\n";

			// Prints out the bottom ASCII line
			PrintLines(numOfChars);

			cout << "\n";

			//Calls the main function again to prompt the user to enter another line
			main();
		}
		else {
			tryAgain = true;

			// Calls the main function so the user can go again
			main();
		}
	}
}
