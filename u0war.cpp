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

int welcome() {

    cout << R"( _____)" << endl;
    cout << R"(|A .  | _____)" << endl;
    cout << R"(| /.\ ||A ^  | _____)" << endl;
    cout << R"(|(_._)|| / \ ||A _  | _____)" << endl;
    cout << R"(|  |  || \ / || ( ) ||A_ _ |)" << endl;
    cout << R"(|____V||  .  ||(_'_)||( v )|)" << endl;
    cout << R"(       |____V||  |  || \ / |)" << endl;
    cout << R"(              |____V||  .  |)" << endl;
    cout << R"(                     |____V|)" << endl;
         
         
         
         
         
            
            
            

    //cout << "Welcome to the game of war! \n" << knight << endl;
    
    return 0;
}

int main() {

    vector<string> deck = newDeck();

    welcome();

    for (int i = 0; i < 52; i++) {
        cout << deck[i] << "   ";
        cout << faceRank(deck[i]) << " " << suitRank(deck[i]) << endl;
    }

    /* // creating a full deck of cards

    // full deck array
    string deck[52][2];

    for (int i = 0; i < 13; i++) {

        // assigning face values
        deck[i][0] = faces[i];
        deck[i + 13][0] = faces[i];
        deck[i + 26][0] = faces[i];
        deck[i + 39][0] = faces[i];
 
        // assigning suits 
        deck[i * 4][1] = suits[0];
        deck[i * 4 + 1][1] = suits[1];
        deck[i * 4 + 2][1] = suits[2];
        deck[i * 4 + 3][1] = suits[3]; 
    } */

}