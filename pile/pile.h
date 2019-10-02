#ifndef _PILE_H_
#define _PILE_H_

#include <vector>
#include "../card/card.h"
#include "../lift/lift.h"

class Pile {
    private:
        std::vector<Card *> cards;
    public:
        Pile();
        ~Pile();

        // Accessors
        unsigned int points();
        unsigned int liftCount();
        Card *getTopCard();
        Card *popTopCard();
        size_t size();

        // Mutators
        Pile &addCardsFrom(Lift &);

        // Void Actions on Pile
        void print();
};

#endif