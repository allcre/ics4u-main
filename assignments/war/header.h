// header file declares functions so they can be used later
#include <string> 
#include <vector>
using namespace std;
  
void instructions();
int faceRank (string card);
int suitRank (string card);
int welcome();
vector<string> newDeck();
vector<string> shuffle(vector<string> deck);
void oneRound();
int check4(string fourCards[2][4], int player);