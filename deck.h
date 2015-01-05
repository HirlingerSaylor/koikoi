#ifndef DECK_H
#define DECK_H
#include "card.h"
#include <QPushButton>

class deck
{
    public:
        deck();
        ~deck();
        void shuffleDeck();
        void dealDeck();
        void playCard(int);//id
        void drawCard();
        void checkMatch(int);//id
        void checkPoints();
        void takeTurns();//simply toggles int turn
        void printStatus();
        int  getTurn();
        int* getQueue();
        int  getPlace();
        card** getCards();
    private:
        int turn;//whose turn, player 1 or 2
        int queue[48];
        int place;
        card* cards[48];
};

#endif // DECK_H
