/******************************************************
** Program: Game.cpp
** Author: Rohan Ballapragada
** Description: The Game class and where the main method is being held Holds a lot of the contents
** Input: Where the user enters in their card to play crazy eights or where you want to draw
** Output: The output is whatever the AI lays out and the card the player selected to draw
******************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include "Deck.cpp"

using namespace std;

class Game { // Game class
    private:  // private variables
        Deck deck;
        Player players[2];
        Card up_card;
        int next_suit;

    public:
        Game () { // Game Constructor
            players[0] = Player("Rohan");
            players[1] = Player("AI");
        }

        ~Game() { // Game destructor
        }

        Card getUpCard() { // Get Card function
            return up_card;
        }

        int getNextSuit() { // Next Suit function
            return next_suit;
        }

        void setNextSuit(int i) { // Set Next Suit function
            next_suit = i;
        }

        Deck getDeck() { // Get Deck function
            return deck;
        }

        Player getPlayer(int i) { // Get Player function
            return players[i];
        }

        void startGame() {
            deck = Deck();
            deck.deckOfCards();
            deck.Shuffle();
            for (int i = 0; i < 7; i++) { // Deals card to Player
                Card c = deck.DealACard();
                players[0].AddCard(c);
            }
            for (int j = 0;j < 7; j++) { // Deals card to computer
                Card c = deck.DealACard();
                players[1].AddCard(c);
            }
            up_card = deck.DealACard();
        }

        bool playCard(int cardnumber) { // Player 1 method
            Hand h = players[0].getHand();
            Card c = h.getCards()[cardnumber];
            if (c.getRank() == 7) { // If player lays down an 8
                cout << "Select Next Suit" << endl;
                cout << "Enter 1 for Hearts" << endl;
                cout << "Enter 2 for Diamond" << endl;
                cout << "Enter 3 for Clubs" << endl;
                cout << "Enter 4 for Spades" << endl;
                int n_suit;
                cin >> n_suit;
                setNextSuit(n_suit - 1);
            } else if ((c.getRank() == up_card.getRank()) || (c.getSuit() == up_card.getSuit())) { 
                // valid card
            } else {
                return false;
            }
            h.RemoveCard(c);
            up_card = c;
            players[0].setHand(h);
            return true;
        }

        bool playCardAI() { // Computer Method
            Hand h = players[1].getHand(); // Assigns hand
            for (int i = 0; i < h.getNumCards(); i++) {
                Card c = h.getCards()[i];
                if (((up_card.getRank() == 8) && (getNextSuit() == c.getSuit()))|| (c.getRank() == up_card.getRank()) || (c.getSuit() == up_card.getSuit())) {
                    h.RemoveCard(c);
                    up_card = c;
                    players[1].setHand(h);
                    return true;
                    break;
                }
                if ((c.getRank() == 7)) { // When AI draws an 8
                    h.RemoveCard(c);
                    up_card = c;
                    players[1].setHand(h);
                    int randnum;
                    srand(time(0));
                    randnum = rand() % 4;
                    setNextSuit(randnum);
                    return true;
                    break;
                }
            }
            return false;
        }

        void drawCard(int player_id) { // draw Card method
            Hand h = players[player_id].getHand();
            Card c = deck.DealACard();
            h.AddCard(c);
            players[player_id].setHand(h);
        }

        int checkWinner() { // checks Winner
            if (players[0].getHand().getNumCards() == 0) { // If the Player has no cards left
                return 1;
            } else if (players[1].getHand().getNumCards() == 0) { // If the Computer has no cards left
                return 2;
            } else if (deck.getNumCards() == 0) { // When the deck is out of cards
                    if (players[0].getHand().getNumCards() < players[1].getHand().getNumCards()) {
                        return 1;
                    } else if (players[0].getHand().getNumCards() > players[1].getHand().getNumCards()) {
                        return 2;
                    } else {
                        return 3;
                    }
            } else {
                return 0;
            }
        }

        void PrintGameStatus() { // Prints headlines 
            cout << "---------- Game Status -------- " << endl;
            cout << "Number of Cards in Deck: " << deck.getNumCards() << endl;
            cout << "Number of Cards in Your Hand: " << players[0].getHand().getNumCards() << endl;
            cout << "Number of Cards in AI Hand: " << players[1].getHand().getNumCards() << endl;
            cout << "--------------------------------" << endl;
        }
};

int main() {
    Game gm = Game();
    gm.startGame();
    while (true) { 
        // Player 1 draw
        while (true) {
            if (gm.checkWinner() > 0) {
                break;
            }
            cout << "************************" << endl;
            cout << "This is your hand" << endl; // Indicates which hand
            gm.getPlayer(0).Print();
            cout << "-------------------" << endl;
            cout << "Up Card Is:" << endl;
            gm.getUpCard().Print(); 
            cout << "Your Turn. Enter Card Number to Play Card or '0' to draw Card" << endl; // Player enters or draws card
            int option;
            cin >> option;
            if (option == 0) { 
                gm.drawCard(0);
            } else {
                while(!gm.playCard(option - 1)) {
                    cout << "You selected incorrect card. Please draw correct card" << endl;
                    cin >> option;
                }
                break;
            }

        }// Player 2 - AI draw
        while (true) {
            if (gm.checkWinner() > 0) {
                break;
            }
            if (gm.playCardAI()) { // AI plays
                cout << "AI played -" << endl;
                gm.getUpCard().Print();
                break;
            } else { // AI draws
                cout << "AI Doesn't have card. Drawing Card From Deck" << endl;
                gm.drawCard(1);
            }
        }
        if (gm.checkWinner() > 0) { // Lines for who won
            if (gm.checkWinner() == 1) {
                cout << "Congradulations! You won!" << endl;
            } else if (gm.checkWinner() == 2) {
                cout << "AI Won! Better Luck Next Time!" << endl;
            } else {
                cout << "Tie Game!" << endl;
            }
            break;
        }
        gm.PrintGameStatus();
    }
    if (gm.checkWinner() > 0) { // Lines for who won
        if (gm.checkWinner() == 1) {
            cout << "Congradulations! You won!" << endl;
        } 
        else if (gm.checkWinner() == 2) {
            cout << "AI Won! Better Luck Next Time!" << endl;
        } 
        else {
            cout << "Tie Game!" << endl;
        }
        cout << "Do you want to play another game? Enter Y or N." << endl;
        char input;
        cin >> input;
        if (input == 'Y') {
            gm.startGame();
        } 
        else {
            exit(1);
        }
    }
}
