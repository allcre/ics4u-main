#include "header.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// global vectors
extern vector<string> deck1;
extern vector<string> deck2;
extern vector<string> discard1;
extern vector<string> discard2;
extern string name1;
extern string name2;
extern int counter1;
extern int counter2;


void oneRound() {
    
    cout << "\n========================== new round ==========================" << endl;

    cout << "\n" << name1 << ", your cards are:" << endl;
    
    string fourCards[2][4]; // array for cards that will be battling this round

    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ": " << deck1[i] << endl; // print options
    }  

    int num; // stores players' choices for order of cards

    start1:
    do {
        cout << "\nWhat order do you want to play your cards in (e.g. 3 1 4 2): ";
        
        for (int j = 0; j < 4; j++) {
            cin >> num;

            while(!cin >> num) { // this stops letters from being accepted as input
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //if the user enters a non-integer
                cout << "That's not a valid input." << endl;
                goto start1; // restarts loop
            }

            if (num > 4 || num < 1) { // faster verification for numbers out of range 
                cout << "That's not a valid input." << endl;
                goto start1;
            }

            fourCards[0][j] = deck1[num - 1]; // populates array with cards that will be played (in order)
        }
    }
    while (check4(fourCards, 1) == 0); // checks that inputs are valid

    // repeat for player 2
    cout << "\n" << name2 << ", your cards are:" << endl;

    for (int k = 0; k < 4; k++) {
        cout << k + 1 << ": " << deck2[k] << endl;
    }  

    start2:
    do {
        cout << "\nWhat order do you want to play your cards in (e.g. 3 1 4 2): ";
        
        for (int l = 0; l < 4; l++) {
            cin >> num;

            while(!cin >> num) { // this stops letters from being accepted as input
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //if the user enters a non-integer
                cout << "That's not a valid input." << endl;
                goto start2; // restarts loop
            }

            if (num > 4 || num < 1) { // faster verification for numbers out of range 
                cout << "That's not a valid input." << endl;
                goto start1;
            }

            fourCards[1][l] = deck2[num - 1]; 
        }
    }
    while (check4(fourCards, 2) == 0);

    // battle starts

    for (int m = 0; m < 4; m++) {

        string card1 = fourCards[0][m];
        string card2 = fourCards[1][m];

        cout << "\n";
        cout << card1 << " vs " << card2 << endl;

        bool winner1; // true if player 1 wins, false if player 2 wins

        if (faceRank(card1) > faceRank(card2)) // compares face values
            winner1 = true;

        else if (faceRank(card1) < faceRank(card2))
            winner1 = false;
        
        else if (faceRank(card1) == faceRank(card2)) { // compares suit values if tie
            if (suitRank(card1) > suitRank(card2))
                winner1 = true;
            else if (suitRank(card1) < suitRank(card2))
                winner1 = false;
            else 
                cout << "you messed up";
        }
        else
            cout << "something's not right...";

        if (winner1) {
            cout << name1 << " wins this round" << endl;
            discard1.push_back(fourCards[0][m]); // adds cards to their discard pile 
            discard1.push_back(fourCards[1][m]);
            counter1++; // increase win counter
        }
        else if (!winner1) {
            cout << name2 << " wins this round" << endl;
            discard2.push_back(fourCards[0][m]);
            discard2.push_back(fourCards[1][m]);
            counter2++;
        }
        else 
            cout << "no";

    }

    // removes the cards that were played from decks
    deck1.erase(deck1.begin(), deck1.begin() + 4);
    deck2.erase(deck2.begin(), deck2.begin() + 4);

    cout << "\n";
    cout << name1 << ", you have " << deck1.size() << " cards left in your playing pile and " << discard1.size() << " cards in your discard pile" << endl;
    cout << name2 << ", you have " << deck2.size() << " cards left in your playing pile and " << discard2.size() << " cards in your discard pile" << endl;
    
    cout << "Press enter to continue";
    cin.get();
    cin.get();
    cin.clear(); // clears any input if people type a number before hitting enter

}