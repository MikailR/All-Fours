#include <iostream>
#include <vector>
#include "hand.h"

using namespace std;

Hand::Hand() {}
Hand::~Hand() {
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        delete *it;
    }
}

Card *Hand::getCardAt(size_t index) {
    if (index >= cards.size()) return nullptr;
    return cards.at(index);
}

Card *Hand::popCardAt(size_t index) {
    if (index >= cards.size()) return nullptr;

    Card *card = cards.at(index);
    cards.erase(cards.begin() + index);

    return card;
}

size_t Hand::size() {
    return cards.size();
}

Hand &Hand::pushBackCard(Card *card) {
    cards.push_back(card);
    return *this;
}

Hand &Hand::moveCard(size_t from, size_t to) {
    if (from >= cards.size()) return *this;
    if (to >= cards.size()) return *this;
    if (from == to) return *this;

    Card *card = this->popCardAt(from);
    cards.insert(cards.begin() + to, card);

    return *this;
}

void Hand::print() {
    if (cards.size() == 0) {
        cout << "Empty Hand" << endl;
    }

    int count = 1;
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        cout << count << ". " << **it << endl;
        ++count;
    }
}
