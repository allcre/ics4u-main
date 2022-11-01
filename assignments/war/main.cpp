// War Game: Created by Allison Cretel 

#include "header.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// global deck vectors
vector<string> deck1; 
vector<string> deck2;
vector<string> discard1;
vector<string> discard2;
int counter1 = 0; // counters keep track of wins for game stats
int counter2 = 0;

// players' names
string name1;
string name2;

// gets player names
void setup() {

    cout << "Player 1, please enter your name: ";
    getline(cin >> ws, name1);

    cout << "Player 2, enter your name: ";
    getline(cin, name2);

    deck1 = newDeck();

    cout << name1 << " vs " << name2 << ", let the game begin!" << endl;
    
    cin.clear(); 
    cin.ignore(10000, '\n');
}

// checks if the game is over, if so declares a winner 
int gameOver() {     
    // return values: 0 = game not over, 1 = p1 won, 2 = p2 won
    if (deck1.size() + discard1.size() < 4)
        return 2;
    else if (deck2.size() + discard2.size() < 4)
        return 1;
    else 
        return 0;

}

int main() {

    welcome();
    cout << "\n";
    setup();

    deck1 = shuffle(deck1); // new shuffled deck
    discard1.clear(); // clearing discard piles
    discard2.clear();
    counter1 = 0; // resetting counters
    counter2 = 0;

    // dealing the deck to both players;
    // deals the first half of the shuffled deck to the second player
    for (int j = 0; j < 26; j++) {
        deck2.push_back(deck1[j]);
    }
    // removes the first half of the deck from the first player's deck
    deck1.erase(deck1.begin(), deck1.begin() + 26);
    
    while(gameOver() == 0) {

        // check if a player needs to shuffle discard into main deck
        if (deck1.size() < 4) {
            for (int k = 0; k < discard1.size(); k++) {
                deck1.push_back(discard1[k]); // moves discarded cards to main pile
            }
            discard1.clear(); // clears discard pile
            deck1 = shuffle(deck1); // shuffles deck
            cout << name1 << ", your cards have been shuffled" << endl;
        } 

        if (deck2.size() < 4) { // for player 2
            for (int l = 0; l < discard2.size(); l++) {
                deck2.push_back(discard2[l]);
            }
            discard2.clear();
            deck2 = shuffle(deck2);
            cout << name2 << ", your cards have been shuffled" << endl;
        } 

        oneRound(); // one round of the game
        gameOver(); // check if the game is over
    } 

    if (gameOver() == 1) {
        cout << "\nCongrats " << name1 << "! You are the winner!" << endl;
    }
    else if (gameOver() == 2) {
        cout << "\nCongrats " << name2 << "! You are the winner!" << endl;
    }
    
    // prints game stats
    cout << "Game Stats:" << endl;
    cout << "The game lasted " << counter1 + counter2 << " rounds" << endl;
    cout << name1 << " won " << counter1 << " rounds " << endl;
    cout << name2 << " won " << counter2 << " rounds " << endl;

    // loop to ask to play again
    bool cont = false;
    do {
        cout << "\nWould you like to play again? (y or n)" << endl;

        string yn = "a"; // temp filler 

        // loop to accept input
        cin >> yn;
        
        if (yn == "y") {
            main();
            cont = true;
        }
        else if (yn == "n")
            return 0;
        else 
            cout << "That's not a valid option, please try again." <<  endl;
    }
    while (!cont);
}