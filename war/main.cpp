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

string name1;
string name2;
bool over = false;

int setup() {

    cout << "What is your name?" << endl;
    cin >> name1;
    string name2 = "andrussy";
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
  return 0;
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
    
    while(!gameOver()) {

        if () // check if a player needs to shuffle discard into main deck

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