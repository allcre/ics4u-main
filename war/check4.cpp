#include "header.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

extern vector<string> deck1;
extern vector<string> deck2;

// checks if the user has entered a valid input for how they want to play their cards
// returns 0 if invalid, returns 1 if valid
// arguments are the array containing the 4 cards to be played, and the player number (1 or 2)

int check4(string fourCards[2][4], int player) { 

    int sum = 0; // should be 1+2+3+4 = 10 if input was good
    int product = 1; // should be 1*2*3*4 = 24 if input was good

    if (player == 1) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (fourCards[0][i] == deck1[j]) {
                    sum += j+1;
                    product *= j+1;
                }
            }
        }
    }
    else { // for player 2
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (fourCards[1][i] == deck2[j]) {
                    sum += j+1;
                    product *= j+1;
                }
            }
        }
    }

    if (sum == 10 && product == 24) {
        return 1; // good to go
    }
    else {
        cout << "That's not a valid input. Make sure you're entering 4 unique numbers from 1-4, seperated by spaces or eneters" << endl;
        return 0;
    }
}