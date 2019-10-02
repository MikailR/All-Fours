#include <iostream>
#include "../table/table.h"

using namespace std;

// TODO: Figure out this error
// - vector in deck gets corruspted when any type of pointer is assigned at the end
Table::Table(): kick(nullptr) {
    deck = new Deck();
    lift = new Lift();
}

Table::~Table() {
    delete deck;
    delete lift;

    // The following is defined to ensure that memory is handled for a cancelled game
    if (kick) { delete kick; }
}

Deck &Table::getDeck() {
    return *deck;
}

Lift &Table::getLift() {
    return *lift;
}

// Note that error handling is implicit
// - a returned nullptr means that there is no kicked card
const Card *Table::getKick() { return kick; }

Rank Table::getKickRank() {
    // TODO: Create custom Exception Classes
    if (!kick) {
        throw "No kicked card!";
    } else {
        return kick->getRank();
    }
}

Suit Table::getKickSuit() {
    if (!kick) {
        throw "No kicked card!";
    } else {
        return kick->getSuit();
    }
}

Table &Table::addKick(Card *card) {
    if (!card) {
        cout << "Cannot kick nothing" << endl;
        cout << "See the function the passed the card pointer" << endl;
        return *this;
    }

    kick = card;
    return *this;
}

Card *Table::removeKick() {
    // Implicit error handling
    Card *temp = kick;
    kick = nullptr;
    return temp; 
}