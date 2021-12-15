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
#include "Hand.cpp"

using namespace std;

class Player { // Player class
    private: // private variables
        Hand hand; 
        string name;
    public:
        Player() {
        }

        // Constructor
        Player(string p_name) { 
            name = p_name;
        }

        // Adds Card to hand
        void AddCard(Card c) {
            hand.AddCard(c);
        }

        // Gets hand
        Hand getHand() {
            return hand;
        }

        // Set Hand method
        void setHand(Hand p_hand) {
            hand = p_hand;
        }

        // Returns Name
        string getName() {
            return name;
        }

        // Prints name
        void Print() {
            cout << name << endl;
            hand.Print();
        }


};
