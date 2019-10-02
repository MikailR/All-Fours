#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "deck.h"

using namespace std;

Deck::Deck() {
    // Initial ordering by suit then rank
    for (int suit = Clubs; suit <= Spades; suit++) {
        for (int rank = Ace; rank <= King; rank++) {
            cards.push_back(new Card(static_cast<Rank>(rank), static_cast<Suit>(suit)));
        }
    }
}

// Note that all cards should be returned to their deck when a game successfully completes
// Also note that objects holding dynamic cards are well-equipped to handle destruction
//  - in other words, all cards do not need to be returned to the deck
Deck::~Deck() {
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        delete *it;
    }
}

// TODO: Refactor this function (and other similar functions) to return constant cards
Card *Deck::getTopCard() {
    if (cards.size() == 0) return nullptr;
    return *cards.begin();
}

Card *Deck::popTopCard() {
    if (cards.size() == 0) return nullptr;

    Card *topCard = *cards.begin();
    cards.erase(cards.begin());
    return topCard;
}

size_t Deck::size() {
    return cards.size();
}

Deck &Deck::pushTopCard(Card *card) {
    // TODO: Refactor for handling card == nullptr

    this->pushCard(0, card);
    return *this;
}

// 0 <= position
// Let pos be (position (mod cards.size()))
// Down shift the cards indices to get pos locations
// The card is inserted at pos
// Note that only position == cards.size() inserts card at the back of the deck
Deck &Deck::pushCard(size_t position, Card *card) {
    // TODO: Refactor for handling card == nullptr

    // Convert position to represent actual deck size
    if (cards.size() == 0) {
        position = 0;
    } else if (position > cards.size()) { // This condition ensures that position == cards.size() is usable
        position = position % cards.size();
    }

    cards.insert(cards.begin() + position, card);
    return *this;
}

Deck &Deck::pushBottomCard(Card *card) {
    if (!card) {
        cout << "Cannot add nothing to the deck" << endl;
    } else {
        this->pushCard(cards.size(), card);
    }
    
    return *this;
}

// Note that this method is here for game cancellation convenience
// In an ideal game, cards move from:
//  1. Lift to Pile
//  2. Pile to Deck
Deck &Deck::pushCardsFrom(Hand &hand) {
    int initialHandSize = hand.size();
    for (int i = 0; i < initialHandSize; ++i) {
        // TODO: Randomize with pushCard(...,...))
        cards.push_back(hand.popCardAt(0));
    }
    return *this;
}

// Note that this method is here for game cancellation convenience
// In an ideal game, cards move from:
//  1. Lift to Pile
//  2. Pile to Deck
Deck &Deck::pushCardsFrom(Lift &lift) {
    int initialLiftSize = lift.size();
    for (int i = 0; i < initialLiftSize; ++i) {
        // TODO: Randomize with pushCard(...,...))
        cards.push_back(lift.popTopCard());
    }
    return *this;
}

Deck &Deck::pushCardsFrom(Pile &pile) {
    int initialPileSize = pile.size();
    for (int i = 0; i < initialPileSize; ++i) {
        // TODO: Randomize with pushCard(...,...))
        cards.push_back(pile.popTopCard());
    }
    return *this;
}

void Deck::print() {
    if (cards.size() == 0) {
        cout << "Empty Deck" << endl;
    }

    int count = 1;
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        cout << count << ". " << **it << endl;
        ++count;
    }
}

Deck &Deck::shuffle() {
    // This is just a basic shuffling algorithm for initial testing
    // TODO: Add customization and complexity
    srand(time(0));

    for (int i = 0; i < size(); ++i) {
        int r = i + (rand() % (size() - i));

        swap(cards[i], cards[r]);
    }

    return *this;
}

// 0 <= position
// Let pos be (position (mod cards.size()))
// Down shift the cards indices to get pos locations
// The deck is cut at pos
// Note that pos == 0 is 'touch deck'
Deck &Deck::cut(size_t position) {
    // TODO: Use dynamic UI to select deck position

    // Convert position to represent actual deck size
    position = position % cards.size();

    // Visualize as cards moving one-by-one from the top of the deck to the bottom of the deck
    Card *inTransit;
    for (int i = 0; i < position; i++) {
        inTransit = *cards.begin();
        cards.push_back(inTransit);
        cards.erase(cards.begin());
    }

    return *this;
}