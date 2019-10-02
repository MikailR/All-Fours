#include <string>
#include "player.h"

using namespace std;

Player::Player(string name, Team *team): name(name), team(team) {
    hand = new Hand();
}

Player::~Player() {
    delete hand;
}

string Player::getName() {
    return name;
}

Team &Player::getTeam() {
    return *team;
}

Hand &Player::getHand() {
    return *hand;
}

Player &Player::pushCardToHand(Card *card) {
    hand->pushBackCard(card);
    return *this;
}

Card *Player::popCardFromHand(size_t index) {
    return hand->popCardAt(index);
}

Player &Player::addDeck(Deck &deck) {
    this->deck = &deck;
    return *this;
}

Deck &Player::removeDeck() {
    Deck *temp = deck;
    deck = nullptr;
    return *temp;
}

bool Player::isDealer() {
    return deck;
}

Player &Player::shuffleDeck() {
    if (!isDealer()) {
        cout << name << " is not the Dealer" << endl;
        return *this;
    }

    // TODO: Consider adding guards for trying to shuffle an empty deck
    deck->shuffle();
    return *this;
}

Player &Player::dealCardTo(Player &player) {
    if (!isDealer()) {
        cout << name << " is not the Dealer" << endl;
        return *this;
    }

    Card *topCard = deck->popTopCard();
    if (topCard) {
        player.pushCardToHand(topCard);
    } else {
        cout << "Cannot deal from an empty deck" << endl;
    }

    return *this;
}

Card *Player::kickCard() {
    if (!isDealer()) {
        cout << name << " is not the Dealer" << endl;
        return nullptr;
    }

    Card *topCard = deck->popTopCard();
    if (!topCard) {
        cout << "Cannot kick from and empty deck" << endl;
        return nullptr;
    }

    return topCard;
}