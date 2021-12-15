/******************************************************
** Program: Game.cpp
** Author: Rohan Ballapragada
** Description: The Game class and where the main method is being held Holds a lot of the contents
*******************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Card { // Card class
    private: // private variables
        int rank; 
        int suit;

    public:
        Card () {
            // default constructor 
        }

        Card(int p_rank, int p_suit) { // Constructor
            rank = p_rank;
            suit = p_suit;
        }

        ~Card() { // Destructor
        }

        int getRank() { // getRank method
            return rank;
        }

        void setRank(int p_rank) { // setRank method
            rank = p_rank;
        }

        int getSuit() { // getSuit method
            return suit;
        }

        void setSuit(int p_suit) { // setSuit method
            suit = p_suit; 
        }

        void Print() { // Print method
            string faces[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
            string suits[4] = {"Hearts", "Diamond", "Clubs", "Spades"};
            cout << faces[rank] << ", " << suits[suit] << endl;
        }
};
