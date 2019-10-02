#ifndef _TEAM_H_
#define _TEAM_H_

#include "../player/player.h"
#include "../pile/pile.h"

class Team {
    private:
        std::string name;
        unsigned int points; // TODO: Create variations to need negative points

        Player *playerOne;
        Player *playerTwo;
        
        Pile *pile;
    public:
        Team(std::tuple<std::string, std::string, std::string>); // Make Players Here
        ~Team();

        // Accessors
        int getPoints();
        Player &getPlayerOne();
        Player &getPlayerTwo();
        Pile &getPile();
};

#endif