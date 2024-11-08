#include "ProgFundChallenge6.h"

enum states {
    Freezing,
    Colder,
    Cold,
    Warm,
    Warmer,
    Hot,
    Hotter,
    Boiling,
    Completed
};

states CheckDiff(int d)
{
    int arr[8]{ 50, 35, 25, 15, 10, 5, 3, 1 };
    bool complete = false;
    int i = 0;

    while (complete == false)
    {
        if (d > arr[i])
        {
            return (states)i;
        }
        else if (arr[i + 1] <= d && d < arr[i])
        {
            return (states)i;
        }
        else if (d == 0)
        {
            return Completed;
        }
        else if (1 <= d && d <= 2)
        {
            return Boiling;
        }
        else {
            i++;
        }
    }
}

int CheckValid()
{
    bool valid = false;
    int guess;

    while (valid == false)
    {
        cout << "-Enter a guess: ";

        if (!(cin >> guess))
        {
            cout << "[!] ERROR: Invalid guess, enter a number in the range 0 - 100.\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
        else if (guess < 0 || guess > 100) {
            cout << "[!] ERROR: Invalid guess, enter a number in the range 0 - 100.\n";
        }
        else {
            valid = true;
            return guess;
        }
    }
}

void SwitchState(states state)
{
    switch (state)
    {
    case Freezing:
        cout << "Freezing\n";
        break;

    case Colder:
        cout << "Colder\n";
        break;

    case Cold:
        cout << "Cold\n";
        break;

    case Warm:
        cout << "Warm\n";
        break;

    case Warmer:
        cout << "Warmer\n";
        break;

    case Hot:
        cout << "Hot\n";
        break;

    case Hotter:
        cout << "Hotter\n";
        break;

    case Boiling:
        cout << "Boiling\n";
        break;

    case Completed:
        break;
    }
}

void GameLoop(bool& win, int randomNum)
{
    int guess = CheckValid();
    int rand = randomNum;
    int diff = abs(guess - rand);
    states currentState = CheckDiff(diff);
    SwitchState(currentState);

    if (currentState == Completed)
    {
        win = true;
    }
}

int main()
{
    int rand = random(0, 100);
    int guessCount = 0;
    bool won = false;

    while (won == false)
    {
        GameLoop(won, rand);
        guessCount++;
    }

    cout << "\n\n>> Correct! The answer was " << rand << "!\n";
    cout << ">> Total number of guesses: " << guessCount;

    return 0;
}