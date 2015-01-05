#include "deck.h"
#include "card.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

deck::deck()
{
    this->place = 0;
    //cout << "The card number is " << this->place << endl;
    this->turn  = 1;
    //cout << "It is player " << this->turn << "'s turn.\n";
    int valueList[48] = {1, 1, 2, 4, 1, 1, 2, 3, 1, 1, 2, 4, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1, 2, 3,
                         1, 1, 2, 3, 1, 1, 3, 4, 1, 1, 2, 5, 1, 1, 2, 3, 1, 2, 3, 4, 1, 1, 1, 4};
    for(int i = 0; i < 48; i++){
        cards[i] = new card( floor( i / 4 ) + 1, valueList[i], i, 5);
        queue[i] = i;
    }
}

deck::~deck()
{

}

void deck::shuffleDeck(){
    srand ( time(NULL) );
    random_shuffle(&queue[0], &queue[48]);
    //find a library that shuffles an array
    //for(int i = 0; i < 48; i++){
        //cout << queue[i] << " ";
    //}
    //cout << endl;
}

void deck::dealDeck(){
    while( place < 24 ){
        //cout << place << ": ";
        if( place >=0 && place < 4 ){
            cards[queue[place]]->setOwner(0);
        }else if( place >= 4 && place < 8 ){
            cards[queue[place]]->setOwner(1);
        }else if( place >= 8 && place < 12 ){
            cards[queue[place]]->setOwner(4);
        }else if( place >= 12 && place < 16 ){
            cards[queue[place]]->setOwner(0);
        }else if( place >= 16 && place < 20 ){
            cards[queue[place]]->setOwner(1);
        }else if( place >= 20 && place < 24 ){
            cards[queue[place]]->setOwner(4);
        }else{
            cout << "Something has gone very wrong!\n";
        }
        //cout << cards[queue[place]]->getId() << endl;
        place++;
    }
}

void deck::playCard(int myid){
/*    cards[myid]->setOwner(3);
    checkMatch(myid);*/
}

void deck::drawCard(){
    //cards[queue[place]]->setOwner(3);
    //checkMatch(queue[place]);
    //place++;
}

void deck::checkMatch(int myid){
/*    int myplayedid = myid;
    int mymonth = cards[myid]->getMonth();
    int nMatches   = 0;
    int indMatches[3] = [-1, -1, -1];
    for(int i = 0; i < 48; i++){
        int checkmonth = cards[i]->getMonth();
        if( checkmonth == mymonth ){
            indMatches[nMatches] = i;
            nMatches++;
        }
    }
    if(nMatches == 1){
        cards[myplayedid]->setOwner(turn);
        cards[indMatches[0]]->setOwner(turn);
    }*/
}

void deck::checkPoints(){
    return;
}

void deck::takeTurns(){
    if( turn == 1 ){
        turn = 2;
    }else if( turn == 2 ){
        turn = 1;
    }else{
        cout << "Something is really wrong!\n";
    }
}

void deck::printStatus(){
    for(int i = 0; i < 48; i++){
        cout << cards[i]->getId()    << " " << cards[i]->getMonth() << " ";
        cout << cards[i]->getValue() << " " << cards[i]->getOwner() << endl;
    }
}

int  deck::getTurn(){
    return turn;
}

int* deck::getQueue(){
    return queue;
}

int  deck::getPlace(){
    return place;
}

card** deck::getCards(){
    return (card**)cards;
}

