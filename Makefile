CrazyEights: Card.cpp Game.cpp Hand.cpp Deck.cpp Player.cpp 
	g++ -std=c++11 -g Card.cpp Game.cpp Hand.cpp Deck.cpp Player.cpp -o CrazyEights

clean:
	rm -f *.o CrazyEights
