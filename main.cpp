#include "header.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> newDeck() {

    // arrays storing strings of card faces and suits
    string faces[13] = {"Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    string suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};

    vector<string> deck; // initializing deck of cards

    // populating the deck
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            deck.push_back(faces[i] + " of " + suits[j]);
        }
    }

    return deck;
}

vector<string> deck = newDeck(); // global deck

int setup() {
  cout << "yuh";
  return 0;
}



int main() {

    welcome();
    cout << "\n";
    setup();
  
    
    for (int i = 0; i < 52; i++) {
        cout << deck[i] << "   ";
        cout << faceRank(deck[i]) << " " << suitRank(deck[i]) << endl;
    }
    
}