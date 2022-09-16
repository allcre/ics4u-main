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
    
    string fourCards[2][4];

    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ": " << deck1[i] << endl;
    }  

    cout << "\nWhat order do you want to play your cards in (e.g. 3 1 4 2): ";
    
    int num;
    for (int j = 0; j < 4; j++) {
        cin >> num;
        fourCards[0][j] = deck1[num - 1]; 
    }

    cout << "\n" << name2 << ", your cards are:" << endl;

    for (int k = 0; k < 4; k++) {
        cout << k + 1 << ": " << deck2[k] << endl;
    }  

    cout << "\nWhat order do you want to play your cards in (e.g. 3 1 4 2): ";
    
    for (int l = 0; l < 4; l++) {
        cin >> num;
        fourCards[1][l] = deck2[num - 1]; 
    }

    // battle starts

    for (int m = 0; m < 4; m++) {

        string card1 = fourCards[0][m];
        string card2 = fourCards[1][m];

        cout << "\n";
        cout << card1 << " vs " << card2 << endl;

        bool winner1; // true if player 1 wins, false if player 2 wins

        if (faceRank(card1) > faceRank(card2))
            winner1 = true;

        else if (faceRank(card1) < faceRank(card2))
            winner1 = false;
        
        else if (faceRank(card1) == faceRank(card2)) {
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
            discard1.push_back(fourCards[0][m]);
            discard1.push_back(fourCards[1][m]);
            counter1++;
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
    
    // fix
    cout << "Press enter to continue" << endl;
    cin.ignore();

}