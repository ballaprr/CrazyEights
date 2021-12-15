/******************************************************
** Program: Game.cpp
** Author: Rohan Ballapragada
** Description: The Game class and where the main method is being held Holds a lot of the contents
******************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Player.cpp"

using namespace std;

class Deck {
  private:
    Card cards[52];
    int numcards;  // Number of cards remaining in the deck.
  public:
    Deck () {
        // Default Constructor
    }

    ~Deck() { // Destructor
    }

    int getNumCards () { // Number of Cards
        return numcards;
    }

    void setNumCards (int p_numcards) { // Set Number of Cards
        numcards = p_numcards;
    }

    void deckOfCards() { // Creates deck
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                cards[cnt] = Card(j,i);
                cnt++;
            }
        }
        numcards = 52;
    }

    void Print() { // Prints cards
        for (int i = 0; i < numcards; i++) {
            cards[i].Print();
        }
    }

    Card DealACard() { // Deals cards
        Card returnCard = cards[0];
        for (int i = 0; i < numcards - 1; i++) {
            cards[i] = cards[i + 1];
        }
        numcards = numcards - 1;
        return returnCard;
    }

    void Shuffle() { // Shuffles cards
        int randnum;
        Card temp;
        srand(time(0));
        for (int i = 0; i < numcards; i++) { 
            randnum = rand() % numcards; // Random Number Generator
            temp = cards[randnum];
            cards[randnum] = cards[i];
            cards[i] = temp;
        }
    }
};
