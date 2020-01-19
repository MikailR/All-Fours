#include <vector>
#include "../table/table.h"
#include "../team/team.h"

class Game {
    private:
        Table *table;
        Team *teamOne;
        Team *teamTwo;

        std::vector<Player *> players;
        size_t dealerIndex;

        void cleanBoard();
        void cleanHands();
        size_t firstDealer();
    public:
        Game(std::tuple<std::string, std::string, std::string>,
             std::tuple<std::string, std::string, std::string>);
        ~Game();

        // Void Actions on Game
        void printDeck();

        // Non-Void Actions on Game
        Game &start();
        Game &end();

        Game &deal(bool = false);
        Game &shiftDealer();
        Game &cleanAll();
};

// Idea: Make first dealer into a mini game
//  - chasing the Jack
//  - etc

// Put all functions to control the game in here
// Let main control the game using these functions
// These functions include things like controlling and error handling
//  - Recall Cards
//  - Pause or cancel game
//  - etc
