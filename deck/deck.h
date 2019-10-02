#ifndef _Deck_H_
#define _Deck_H_

#include "../card/card.h"
#include "../hand/hand.h"
#include "../lift/lift.h"
#include "../pile/pile.h"

class Deck {
    private:
        std::vector<Card *> cards;
    public:
        Deck();
        ~Deck();

        // Accessors
        Card *getTopCard();
        Card *popTopCard();
        size_t size();
        
        // Mutators
        Deck &pushTopCard(Card *);
        Deck &pushCard(std::size_t, Card *);
        Deck &pushBottomCard(Card *);
        Deck &pushCardsFrom(Hand &);
        Deck &pushCardsFrom(Lift &);
        Deck &pushCardsFrom(Pile &);

        // Void Actions on Deck
        void print();

        // Non-Void Actions on Deck
        Deck &shuffle(); // include attributes for different shuffling algorithms
        Deck &cut(std::size_t);
};

#endif