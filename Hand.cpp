/******************************************************
** Program: Game.cpp
** Author: Rohan Ballapragada
** Description: The Game class and where the main method is being held Holds a lot of the content
******************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include "Card.cpp"

using namespace std;

class Hand { // Hand Class
  private:
    Card* cards;
    int numcards;  // Number of cards in the hand.
  public:
    Hand() { // Hand Constructor
        numcards = 0;
        cards = new Card[7];
    }

    ~Hand() { // Destructor
    }

    Card* getCards() { // Return Cards method
        return cards;
    }

    int getNumCards() {
        return numcards;
    }

    void AddCard(Card c) { // Add Card method
        cards[numcards] = c;
        numcards = numcards + 1;
    }

    // Remove Card method
    void RemoveCard(Card c) { 
        for (int i = 0; i < numcards; i++) { // Goees through each card in the hand 
            if ((cards[i].getRank() == c.getRank()) && (cards[i].getSuit() == c.getSuit())) {
                for (int j = i; j < numcards - 1; j++) {
                        cards[j] = cards[j + 1];
                }
                break;
            }
        }
        numcards = numcards - 1;
    }

    bool ContainsCard(Card c) {
        for (int i = 0; i < numcards; i++) { // Checks to see if right card's contained
            if ((cards[i].getRank() == c.getRank()) && (cards[i].getSuit() == c.getSuit())) {
                return true;
            }
        }
        return false;
    }

    void Print() { // Print function
        cout << "Number of Cards in Hand:" << numcards << endl; 
        string faces[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
        string suits[4] = {"Hearts", "Diamond", "Clubs", "Spades"};
        for (int i = 0; i < numcards; i++) {
                cout << (i + 1) << ") " << faces[cards[i].getRank()] << "," << suits[cards[i].getSuit()] << endl;
        }
    }

};
