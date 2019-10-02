#ifndef _HAND_H_
#define _HAND_H_

#include <vector>
#include "../card/card.h"

class Hand {
    private:
        std::vector<Card *> cards;
    public:
        Hand();
        ~Hand();

        // Accessors
        Card *getCardAt(std::size_t);
        Card *popCardAt(std::size_t);
        size_t size();

        // Mutators
        Hand &pushBackCard(Card *);
        Hand &moveCard(std::size_t, std::size_t); // This is for moving cards in the deck

        // Void Actions on Hand
        void print();
};

#endif