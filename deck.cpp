#include "deck.h"
#include "card.h"
#include <iostream>
using namespace std;

deck::deck()
{
    this->place = 0;
    cout << "The card number is " << this->place << endl;
    this->turn  = 1;
    cout << "It is player " << this->turn << "'s turn.\n";
    cards[0 ] = new card(1 , 1, 0 , 0);    cards[1 ] = new card(1 , 1, 1 , 0);
    cards[2 ] = new card(1 , 1, 2 , 0);    cards[3 ] = new card(1 , 1, 3 , 0);
    cards[4 ] = new card(2 , 1, 4 , 0);    cards[5 ] = new card(2 , 1, 5 , 0);
    cards[6 ] = new card(2 , 1, 6 , 0);    cards[7 ] = new card(2 , 1, 7 , 0);
    cards[8 ] = new card(3 , 1, 8 , 0);    cards[9 ] = new card(3 , 1, 9 , 0);
    cards[10] = new card(3 , 1, 10, 0);    cards[11] = new card(3 , 1, 11, 0);
    cards[12] = new card(4 , 1, 12, 0);    cards[13] = new card(4 , 1, 13, 0);
    cards[14] = new card(4 , 1, 14, 0);    cards[15] = new card(4 , 1, 15, 0);
    cards[16] = new card(5 , 1, 16, 0);    cards[17] = new card(5 , 1, 17, 0);
    cards[18] = new card(5 , 1, 18, 0);    cards[19] = new card(5 , 1, 19, 0);
    cards[20] = new card(6 , 1, 20, 0);    cards[21] = new card(6 , 1, 21, 0);
    cards[22] = new card(6 , 1, 22, 0);    cards[23] = new card(6 , 1, 23, 0);
    cards[24] = new card(7 , 1, 24, 0);    cards[25] = new card(7 , 1, 25, 0);
    cards[26] = new card(7 , 1, 26, 0);    cards[27] = new card(7 , 1, 27, 0);
    cards[28] = new card(8 , 1, 28, 0);    cards[29] = new card(8 , 1, 29, 0);
    cards[30] = new card(8 , 1, 30, 0);    cards[31] = new card(8 , 1, 31, 0);
    cards[32] = new card(9 , 1, 32, 0);    cards[33] = new card(9 , 1, 33, 0);
    cards[34] = new card(9 , 1, 34, 0);    cards[35] = new card(9 , 1, 35, 0);
    cards[36] = new card(10, 1, 36, 0);    cards[37] = new card(10, 1, 37, 0);
    cards[38] = new card(10, 1, 38, 0);    cards[39] = new card(10, 1, 39, 0);
    cards[40] = new card(11, 1, 40, 0);    cards[41] = new card(11, 1, 41, 0);
    cards[42] = new card(11, 1, 42, 0);    cards[43] = new card(11, 1, 43, 0);
    cards[44] = new card(12, 1, 44, 0);    cards[45] = new card(12, 1, 45, 0);
    cards[46] = new card(12, 1, 46, 0);    cards[47] = new card(12, 1, 47, 0);
    for(int i = 0; i < 48; i++){
        queue[i] = i;
    }
}

deck::~deck()
{
    cout << "Goodbye. Thank you for playing.\n";
}

void deck::shuffleDeck(){

    //find a library that shuffles an array
}

void deck::dealDeck(){
    while( place < 24 ){
        //cout << place << endl;
        if( place >=0 && place < 4 ){
            cards[queue[place]]->setOwner(1);
        }else if( place >= 4 && place < 8 ){
            cards[queue[place]]->setOwner(2);
        }else if( place >= 8 && place < 12 ){
            cards[queue[place]]->setOwner(3);
        }else if( place >= 12 && place < 16 ){
            cards[queue[place]]->setOwner(1);
        }else if( place >= 16 && place < 20 ){
            cards[queue[place]]->setOwner(2);
        }else if( place >= 20 && place < 24 ){
            cards[queue[place]]->setOwner(3);
        }else{
            cout << "Something has gone very wrong!\n";
        }
        place++;
    }
}

void deck::playCard(int myid){
/*    cards[myid]->setOwner(3);
    checkMatch(myid);*/
}

void deck::drawCard(){
    cards[queue[place]]->setOwner(3);
    checkMatch(queue[place]);
    place++;
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

card*deck::getCards(){
    //card* card_ptr = cards;
    //return card_ptr;
}


