// ProgFundChallenge5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void PrintUpperLower(bool isUpper, string sentence)
{
    if (isUpper)
    {
        for (char& c : sentence)
        {
            c = toupper(c);
            cout << c;
        }
    }
    else
    {
        for (char& c : sentence)
        {
            c = tolower(c);
            cout << c;
        }
    }
}

void SentenceCasing(string sentence)
{
    bool up = false;

    for (char& c : sentence)
    {

        if (c == sentence[0])
        {
            c = toupper(c);
            cout << c;
        }
        else if (up == true && isalpha(c))
        {
            c = toupper(c);
            cout << c;
            up = false;
        }
        else if (up == false && isalpha(c) || c == ' ')
        {
            c = tolower(c);
            cout << c;
        }
        else
        {
            up = true;
            cout << c;
        }
    }
}

void AlternateCasing(string sentence)
{
    bool up = false;

    for (char& c : sentence)
    {
        if (up == true && isalpha(c))
        {
            c = toupper(c);
            cout << c;
            up = false;
        }
        else if (up == false && isalpha(c))
        {
            c = tolower(c);
            cout << c;
            up = true;
        }
        else
        {
            cout << c;
        }
    }
}

int main()
{
    string userInput;
    bool valid = false;

    cout << "- Please enter a sentence: ";
    getline(cin, userInput);

    for (char& c : userInput)
    {
        if (isalpha(c))
        {
            if (isdigit(c))
            {
                cerr << "ERROR[!]: INVALID SENTENCE, NUMBER DETECTED!";
                exit(0);
            }
            else
            {
                valid = true;
            }
        }
        else if (!isalpha(c) && !valid)
        {
            cerr << "ERROR[!]: INVALID SENTENCE, NO ALPHABETICAL CHARACTERS DETECTED!";
            exit(0);
        }
    }

    cout << "\n\nUppercase\t\t=> ";
    PrintUpperLower(true, userInput);

    cout << "\n\nLowercase\t\t=> ";
    PrintUpperLower(false, userInput);

    cout << "\n\nSentence Case\t\t=> ";
    SentenceCasing(userInput);

    cout << "\n\nAlternate Case\t\t=> ";
    AlternateCasing(userInput);
}