#include <iostream>
#include "card.h"

using namespace std;

Card::Card(Rank rank, Suit suit): rank(rank), suit(suit) {}
Card::~Card () {}

Rank Card::getRank() {
    return rank;
}

Suit Card::getSuit() {
    return suit;
}

void Card::print() {
    cout << rankString() << " of " << suitString() << endl;
}

ostream &operator<<(ostream &out, const Card &card) {
    out << card.rankString() << " of " << card.suitString();
    return out;
}


// Private Functions

string Card::rankString() const {
    string rank;

    // These comparisons are based on the Rank Enumeration
    switch (this->rank) {
        case Ace:
            rank = "Ace";
            break;
        case Two:
            rank = "Two";
            break;
        case Three:
            rank = "Three";
            break;
        case Four:
            rank = "Four";
            break;
        case Five:
            rank = "Five";
            break;
        case Six:
            rank = "Six";
            break;
        case Seven:
            rank = "Seven";
            break;
        case Eight:
            rank = "Eight";
            break;
        case Nine:
            rank = "Nine";
            break;
        case Ten:
            rank = "Ten";
            break;
        case Jack:
            rank = "Jack";
            break;
        case Queen:
            rank = "Queen";
            break;
        case King:
            rank = "King";
            break;
        default:
            rank = "Assignment Failed";
            break;
    }

    return rank;
}

string Card::suitString() const {
    string suit;

    // These comparisons are based on the Suit Enumeration
    switch (this->suit) {
        case Clubs:
            suit = "Clubs";
            break;
        case Diamonds:
            suit = "Diamonds";
            break;
        case Hearts:
            suit = "Hearts";
            break;
        case Spades:
            suit = "Spades";
            break;
        default:
            suit = "Assignment Failed";
            break;
    }

    return suit;
}