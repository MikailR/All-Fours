#include <iostream>
#include <tuple>
#include "../game/game.h"

using namespace std;

// Conventions
//  - if an heap allocated object member from a class is being accessed/used
//    - store in a Reference Variable (not being removed)
//    - store in a Pointer Variable (is being removed)

// TODOS:
//  - Convert all local error messages into thrown errors
//  - Refactor code to exceptions with appropriate catching
//  - Include error handling for all functions that move cards around
//    - Eg: pushCard, pushBottomCard, pushTopCard

int main() {
    // Main Game
    cout << endl << "All Fours" << endl << endl;
    
    string teamName;
    string playerOne;
    string playerTwo;

    cout << "Enter the Name of Team One: ";
    getline(cin, teamName);
    cout << "Player One: ";
    getline(cin, playerOne);
    cout << "Player Two: ";
    getline(cin, playerTwo);
    auto teamOneMeta = make_tuple(teamName, playerOne, playerTwo);
    cout << endl;

    cout << "Enter the Name of Team Two: ";
    getline(cin, teamName);
    cout << "Player One: ";
    getline(cin, playerOne);
    cout << "Player Two: ";
    getline(cin, playerTwo);
    auto teamTwoMeta = make_tuple(teamName, playerOne, playerTwo);
    cout << endl;

    Game game = Game(teamOneMeta, teamTwoMeta);
    game.start();
    game.deal();
    game.deal(true);
    
    return 0;
}


// Stuff that might come in handy

// Some arbitrary card pointer allocations
    // Card *card1 = new Card(Ace, Spades);
    // Card *card2 = new Card(Five, Hearts);
    // Card *card3 = new Card(Four, Diamonds);
    // Card *card4 = new Card(Eight, Clubs);
    // Card *card5 = new Card(Seven, Hearts);
    // Card *card6 = new Card(Two, Spades);
    // Card *card7 = new Card(Nine, Clubs);
    // Card *card8 = new Card(Six, Diamonds);