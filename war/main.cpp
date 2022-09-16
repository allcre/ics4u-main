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

string name1;
string name2;
bool over = false; // for playing again

void setup() {

    cout << "Player 1, please enter your name: ";
    cin >> name1;

    cout << "Player 2, enter your name: ";
    cin >> name2;

    deck1 = newDeck();

    cout << name1 << " vs " << name2 << ", let the game begin!" << endl;

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

    deck1 = shuffle(deck1);

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
                deck1.push_back(discard1[k]);
            }
            discard1.erase(discard1.begin(), discard1.begin() + discard1.size());
            shuffle(deck1);
            cout << name1 << ", your cards have been shuffled" << endl;
        } 

        if (deck2.size() < 4) {
            for (int l = 0; l < discard2.size(); l++) {
                deck2.push_back(discard2[l]);
            }
            discard2.erase(discard2.begin(), discard2.begin() + discard2.size());
            shuffle(deck2);
            cout << name2 << ", your cards have been shuffled" << endl;
        } 

        oneRound(); // pass 2 player or bot ig
        gameOver();
    } 
  
    /*
    for (int i = 0; i < 26; i++) {
        cout << deck1[i] << "  1 " << endl;
        cout << deck2[i] << "   2" << endl;
        //cout << faceRank(deck1[i]) << " " << suitRank(deck1[i]) << endl;
    }

    cout << deck1.size() << deck2.size(); */
    
}