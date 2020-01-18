#include <string>
#include <tuple>
#include "team.h"

using namespace std;

Team::Team(tuple<string, string, string> teamMeta): points(0) {
    string name; string playerOne; string playerTwo;
    tie(name, playerOne, playerTwo) = teamMeta;

    this->playerOne = new Player(playerOne, this);
    this->playerTwo = new Player(playerTwo, this);

    this->pile = new Pile();
}

Team::~Team() {
    delete playerOne;
    delete playerTwo;

    delete pile;
}

int Team::getPoints() {
    return points;
}

Player &Team::getPlayerOne() {
    return *playerOne;
}

Player &Team::getPlayerTwo() {
    return *playerTwo;
}

Pile &::Team::getPile() {
    return *pile;
}