#ifndef _CARD_H_
#define _CARD_H_

#include <iostream>
#include "../enums/suit.h"
#include "../enums/rank.h"

// Notes
// - No default card (must be specified upon creation)
// - Consider adding a ghost card toggle for memory purposes
//
// TODO: Add connections for Deck, Players, Table, Piles, etc

class Card {
    private:
        Rank rank;
        Suit suit;

        std::string rankString() const;
        std::string suitString() const;
    public:
        Card(Rank, Suit);
        ~Card();

        // Accessors
        Rank getRank();
        Suit getSuit();

        // Void Actions on Card
        void print();

        // Overloads
        friend std::ostream &operator<<(std::ostream &, const Card &);
};

#endif