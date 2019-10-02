#ifndef _TABLE_H_
#define _TABLE_H_

#include <vector>
#include "../deck/deck.h"
#include "../lift/lift.h"

class Table {
    private:
        Deck *deck;
        Card *kick; // TODO: Find an elegant way to KICK the Trump card and STORE it
        Lift *lift; // TODO: Consider using static memory to host the on table lifts
    public:
        Table();
        ~Table();

        // Accessors
        Deck &getDeck();
        Lift &getLift();
        const Card *getKick();
        Rank getKickRank();
        Suit getKickSuit();


        // Mutators
        Table &addKick(Card *);
        Card *removeKick();
};

#endif