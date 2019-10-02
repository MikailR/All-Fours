CXX = g++
CXXFLAGS = -Wall -g -std=c++17

allfours: main.o card.o deck.o game.o hand.o lift.o pile.o player.o table.o team.o
	$(CXX) $(CXXFLAGS) -o allfours main.o card.o deck.o game.o hand.o lift.o pile.o player.o table.o team.o

card.o: card/card.cc card/card.h
	$(CXX) $(CXXFLAGS) -c card/card.cc

deck.o: deck/deck.cc deck/deck.h
	$(CXX) $(CXXFLAGS) -c deck/deck.cc

game.o: game/game.cc game/game.h
	$(CXX) $(CXXFLAGS) -c game/game.cc

hand.o: hand/hand.cc hand/hand.h
	$(CXX) $(CXXFLAGS) -c hand/hand.cc

lift.o: lift/lift.cc lift/lift.h
	$(CXX) $(CXXFLAGS) -c lift/lift.cc

main.o: main/main.cc
	$(CXX) $(CXXFLAGS) -c main/main.cc

pile.o: pile/pile.cc pile/pile.h
	$(CXX) $(CXXFLAGS) -c pile/pile.cc

player.o: player/player.cc player/player.h
	$(CXX) $(CXXFLAGS) -c player/player.cc

table.o: table/table.cc table/table.h
	$(CXX) $(CXXFLAGS) -c table/table.cc

team.o: team/team.cc team/team.h
	$(CXX) $(CXXFLAGS) -c team/team.cc

clean:
	-rm *.o $(objects)