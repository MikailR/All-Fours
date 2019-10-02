#include <iostream>
#include "pile.h"

using namespace std;

Pile::Pile() {}
Pile::~Pile() {
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        delete *it;
    }
}

unsigned int Pile::points() {
    unsigned int points = 0;

    for (auto it = cards.begin(); it != cards.end(); ++it) {
        Rank rank = (**it).getRank();
        switch (rank) {
            case Ace:
                points += 4;
                break;
            case Ten:
                points += 10;
                break;
            case Jack:
                points += 1;
                break;
            case Queen:
                points += 2;
                break;
            case King:
                points += 3;
                break;
            default:
                break;
        }
    }

    return points;
}

unsigned int Pile::liftCount() {
    return cards.size() / 4;
}

Card *Pile::getTopCard() {
    if (cards.size() == 0) return nullptr;
    return *cards.begin();
}

Card *Pile::popTopCard() {
    if (cards.size() == 0) return nullptr;

    Card *topCard = *cards.begin();
    cards.erase(cards.begin());
    return topCard;
}

size_t Pile::size() {
    return cards.size();
}

Pile &Pile::addCardsFrom(Lift &lift) {
    int initialLiftSize = lift.size();
    for (int i = 0; i < initialLiftSize; i++) {
        cards.push_back(lift.popTopCard());
    }

    return *this;
}

void Pile::print() {
    if (cards.size() == 0) {
        cout << "Empty Pile" << endl;
    }

    int count = 1;
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        cout << count << ". " << (**it) << endl;
        ++count;
    }
}