#include "header.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// global deck vectors
vector<string> deck1 = newDeck(); 
vector<string> deck2;
vector<string> discard1;
vector<string> discard2;
int counter1 = 0; // counters keep track of wins for game stats
int counter2 = 0;

string name1;
string name2;
bool over = false;

void setup() {

    cout << "Player 1, please enter your name: ";
    cin >> name1;

    cout << "Player 2, enter your name: ";
    cin >> name2;

    cout << "Ok " << name1 << ", you will be playing against " << name2 << endl;

/*
    cout << "Ok " << name << ", you have two options:" << endl;
    cout << "Option 1: Play against your friend" << endl;
    cout << "Option 2: Play against a bot" << endl;
    cout << "1 or 2 :";

    string name2 = "andrussy"; // could make an array with random names to give to bots

    int n = 0;

    while (n != (1 || 2)) {
        cin >> n;
        if (n == 1) {
            cout << "What is your friend's name?" << endl;
            cin >> name2;
            cout << "Ok, you will be playing against " << name2 << endl;
            return 0;
        } 
        else if (n == 2) {
            cout << "Ok, you will be playing against " << name2 << endl;
            return 0;
        }
        else {
            cout << "Please enter 1 or 2:";
        }
    }
*/
  
}

bool gameOver() {     
    if (deck1.size() + discard1.size() < 4)
        return true;
    else if (deck2.size() + discard2.size() < 4)
        return true;
    else 
        return false;

}

void oneRound() {
    
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
        cout << card1 << " vs " << card2;

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

    cout << "\n";
    cout << name1 << ", you have " << deck1.size() << " cards left in your playing pile and " << discard1.size() << " cards in your discard pile" << endl;
    cout << name2 << ", you have " << deck2.size() << " cards left in your playing pile and " << discard2.size() << " cards in your discard pile" << endl;


}

int main() {

    welcome();
    cout << "\n";
    setup();

    deck1 = shuffle(deck1);

    // dealing the deck to both players;
    // deals the first half of the shuffled deck to the second player
    for (int j = 0; j < 26; j++) {
        deck2.push_back(deck1[j]);
    }
    // removes the first half of the deck from the first player's deck
    deck1.erase(deck1.begin(), deck1.begin() + 26);
    
    //while(!gameOver()) {

         // check if a player needs to shuffle discard into main deck

        oneRound(); // pass 2 player or bot ig
        gameOver();
    //} 
  
    /*
    for (int i = 0; i < 26; i++) {
        cout << deck1[i] << "  1 " << endl;
        cout << deck2[i] << "   2" << endl;
        //cout << faceRank(deck1[i]) << " " << suitRank(deck1[i]) << endl;
    }

    cout << deck1.size() << deck2.size(); */
    
}