#ifndef _LIFT_H_
#define _LIFT_H_

#include <vector>
#include "../card/card.h"

class Lift {
    private:
        std::vector<Card *> cards;
    public:
        Lift();
        ~Lift();

        // TODO: Implement an elegant function for giving lift to winning team

        // Accessors
        Card *getCardAt(size_t);
        Card *popTopCard();
        size_t size();

        // Mutators
        Lift &pushBackCard(Card *);

        // Void Actions on Lift
        void print();
};

#endif