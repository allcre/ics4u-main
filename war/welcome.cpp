#include "header.h"
#include <iostream>
#include <string>
using namespace std;

// welcomes player to the game
int welcome() {

    // ascii art 
    /*
    cout << R"( _____)" << endl;
    cout << R"(|A .  | _____)" << endl;
    cout << R"(| /.\ ||A ^  | _____)" << endl;
    cout << R"(|(_._)|| / \ ||A _  | _____)" << endl;
    cout << R"(|  |  || \ / || ( ) ||A_ _ |)" << endl;
    cout << R"(|____V||  .  ||(_'_)||( v )|)" << endl;
    cout << R"(       |____V||  |  || \ / |)" << endl;
    cout << R"(              |____V||  .  |)" << endl;
    cout << R"(                     |____V|)" << endl;
    */

    cout << "\nWelcome to the game of war! \n" << endl;
  
    string yn = "a"; // temp filler 

    // loop to print instructions 
    while (yn != "y" || "n") {
      cout << "Would you like to read the instructions? (y or n)" << endl;
      cin >> yn;
      
      if (yn == "y") {
        instructions();
        return 0;
      }
      else if (yn == "n") {
        return 0;
      }
      else 
        cout << "That's not a valid option, please try again." <<  endl;
    }
      
    return 0;
}