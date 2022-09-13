#include "header.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> // this is where srand() is defined
#include <ctime> // this is where time() is defined
using namespace std;

vector<string> shuffle(vector<string> deck) {

    int n = deck.size(); // gets size of the deck

    srand (time(NULL)); // ensures that rand() generates new random numbers

    for (int i = 0; i < n - 1; i++) {
        int j = i + rand() % (n - i); // generates a random index number between i and the end of the deck
        swap(deck[i], deck[j]); // swaps the card at i with a card further in the deck
    }

    return deck;
}

