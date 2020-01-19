#include <iostream>
#include <tuple>
#include "game.h"

using namespace std;

Game::Game(tuple<string, string, string> teamOneMeta, 
           tuple<string, string, string> teamTwoMeta) {
    table = new Table();
    teamOne = new Team(teamOneMeta);
    teamTwo = new Team(teamTwoMeta);

    // Each player is added to the vector for coding convenience
    players.push_back(&teamOne->getPlayerOne());
    players.push_back(&teamTwo->getPlayerOne());
    players.push_back(&teamOne->getPlayerTwo());
    players.push_back(&teamTwo->getPlayerTwo());

    dealerIndex = 0;
}

Game::~Game() {
    delete table;
    delete teamOne;
    delete teamTwo;
}

void Game::printDeck() {
    table->getDeck().print();
}

Game &Game::start() {
    table->getDeck().shuffle();
    dealerIndex = firstDealer();

    players.at(dealerIndex)->addDeck(table->getDeck());
    cout << "Dealer by First Jack is: " << players.at(dealerIndex)->getName() << endl;

    return *this;
}

Game &Game::end() {
    // TODO: Implement
    return *this;
}

Game &Game::shiftDealer() {
    size_t lastDealerIndex = dealerIndex;
    ++dealerIndex;
    dealerIndex %= 4;

    players.at(dealerIndex)->addDeck(players.at(lastDealerIndex)->removeDeck());
    cout << "New Dealer is: " << players.at(dealerIndex)->getName() << endl;

    return *this;
}

// Note that this function must be called at the end of each round
Game &Game::cleanAll() {
    cleanBoard();
    cleanHands();
    return *this;
}


// Private Functions

void Game::cleanBoard() {
    table->getDeck().pushBottomCard(table->removeKick());
    table->getDeck().pushCardsFrom(teamOne->getPile());
    table->getDeck().pushCardsFrom(teamTwo->getPile());
    if (table->getLift().size() != 0) {
        table->getDeck().pushCardsFrom(table->getLift());
    }
}

void Game::cleanHands() {
    if (table->getDeck().size() == 52) return; // Reduces computation time
    table->getDeck().pushCardsFrom(teamOne->getPlayerOne().getHand());
    table->getDeck().pushCardsFrom(teamTwo->getPlayerOne().getHand());
    table->getDeck().pushCardsFrom(teamOne->getPlayerTwo().getHand());
    table->getDeck().pushCardsFrom(teamTwo->getPlayerTwo().getHand());
}

size_t Game::firstDealer() {
    // First Jack deal starts with player two
    size_t index = 1;
    Deck &deck = table->getDeck();
    while (true) {
        players.at(index % 4)->pushCardToHand(deck.popTopCard());
        Rank rank = players.at(index % 4)->getHand().getCardAt((index - 1) / 4)->getRank();
        if (rank == Jack) {
            index %= 4;
            break;
        } else {
            ++index;
        }
    }

    cleanHands();
    return index;
    
}

Game &Game::deal() {
    //table->getDeck().print();
    //cout << endl;
    int cardRecipient = dealerIndex + 1;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 4; j++) {
            players.at(dealerIndex)->dealCardTo(*players.at(cardRecipient % 4));
            cardRecipient++;
        }
    }
    table->addKick(players.at(dealerIndex)->kickCard());
    players.at(dealerIndex)->getHand().print();
    table->getKick()->print();
    //cout << endl;
    //table->getDeck().print();

    return *this;
}