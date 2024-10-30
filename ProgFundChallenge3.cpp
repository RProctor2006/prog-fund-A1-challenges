// ProgFundChallenge3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;

enum appErrors {
    ERROR_INVALID_INPUT = 1
};

int main()
{
    float playerNum;

    cout << "Please enter a number: ";

    if (!(cin >> playerNum)) {

        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cerr << "Error: That was not a number.\n";
        return ERROR_INVALID_INPUT;
    }

    float negation = playerNum * -1;
    float squared = pow(playerNum, 2);
    float cubed = pow(playerNum, 3);
    float fcr[3] = { floor(playerNum), ceil(playerNum), round(playerNum) };

    cout << "\nThe negation of " << playerNum << " is " << negation << endl;
    cout << "The absolute value of " << playerNum << " is " << abs(playerNum) << endl;
    cout << "The square of " << playerNum << " is " << squared << endl;
    cout << "The cube of " << playerNum << " is " << cubed << endl;

    if (playerNum < 0) {
        cout << "The square root of " << playerNum << " does not exist as it is a negative. If it were a positive it would be " << sqrtf(playerNum * -1) << endl;
    }
    else {
        cout << "The square root of " << playerNum << " is " << sqrtf(playerNum) << endl;
    }

    cout << "The floor of " << playerNum << " is " << fcr[0] << "\nThe ceiling is " << fcr[1] << "\nThe rounded value is " << fcr[2];
}
