#include "header.h"
#include <iostream>
using namespace std;

// prints instructions
void instructions() {
  cout << "\n1. A deck of 52 cards is shuffled, and each player receives half the deck.\n" << endl;
  cout << "2. Both players draw 4 cards from their pile, look at them, and choose the order to play them in.\n" << endl; 
  cout << "3. Once each player has chosen, cards are then compared in the order they chose, and the winner of each “battle” takes the cards as normal (they go to that players discard pile). Twos are low (equal to 2), Aces are high (equal to 14).\n" << endl; 
  cout << "4. In the event of a numerical tie, suit is the tiebreaking factor. Suits are listed from strongest to weakest as follows: Clubs, Diamonds, Hearts, Spades (notice they are alphabetical).\n" << endl;
  cout << "5. Players now lose if they are unable to draw 4 cards from their pile at the start of their turn (including cards in discard pile, which would be shuffled in if needed). Shuffling should only happen when a players pile drops below 4 cards (not each time the player wins cards).\n" << endl;

  cin.clear();
  cin.ignore(10000, '\n');
}