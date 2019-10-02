#include <iostream>
#include "lift.h"

using namespace std;

Lift::Lift() {};
Lift::~Lift() {
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        delete *it;
    }
};

Card *Lift::getCardAt(size_t index) {
    return cards.at(index);
}

Card *Lift::popTopCard() {
    if (cards.size() == 0) return nullptr;

    Card *topCard = *cards.begin();
    cards.erase(cards.begin());
    return topCard;
}

size_t Lift::size() {
    return cards.size();
}

Lift &Lift::pushBackCard(Card *card) {
    if (card == nullptr) {
        cout << "Cannot add a nullptr to the Lift" << endl;
        return *this;
    }

    cards.push_back(card);
    return *this;
}

void Lift::print() {
    if (cards.size() == 0) {
        cout << "Empty Lift" << endl;
    }

    int count = 1;
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        cout << count << ". " << **it << endl;
        ++count;
    }
}