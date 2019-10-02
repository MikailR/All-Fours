#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string> // TODO: Find a different way to silence Type Error
#include "../deck/deck.h"
#include "../hand/hand.h"

class Team; // Forward Declaration

class Player {
    private:
        // Meta-Info
        std::string name;
        Team *team;
        
        // Note: Player only has access to the deck when they are the dealer
        Hand *hand;
        Deck *deck;
    public:
        Player(std::string, Team *);
        ~Player();

        // Accessors
        std::string getName();
        Team &getTeam();
        Hand &getHand();

        // Hand Functions
        Player &pushCardToHand(Card *);
        Card *popCardFromHand(std::size_t);

        // Dealer Functions
        Player &addDeck(Deck &);
        Deck &removeDeck();
        bool isDealer();
        Player &shuffleDeck();
        Player &dealCardTo(Player &);
        Card *kickCard();
};

#endif