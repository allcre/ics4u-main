#include "header.h"
#include <iostream>
#include <string>
using namespace std;

// returns numerical value of the card 
int faceRank (string card) {
    
    // first finds the position of the first space, so the value of the card can be found just before the space
    size_t pos = card.find(' ');
    string face = card.substr(0, pos);

    // assigning numerical values to faces
    if (face == "Deuce")
        return 2;
    else if (face == "Three")
        return 3;
    else if (face == "Four")
        return 4;
    else if (face == "Five")
        return 5;
    else if (face == "Six")
        return 6;
    else if (face == "Seven")
        return 7;
    else if (face == "Eight")
        return 8;
    else if (face == "Nine")
        return 9;
    else if (face == "Ten")
        return 10;
    else if (face == "Jack")
        return 11;
    else if (face == "Queen")
        return 12;
    else if (face == "King")
        return 13;
    else 
        return 14;
}

// returns value of the card's suit (4 = highest)
int suitRank (string card) {

    // finds position of the word "of" to locate the suit
    size_t pos = card.find("of");
    string suit = card.substr(pos + 3, card.length() - pos + 2);

    // assign value to suit
    if (suit == "Clubs")
        return 4;
    else if (suit == "Diamonds")
        return 3;
    else if (suit == "Hearts")
        return 2;
    else
        return 1;
}