#include "mainwindow.h"
#include <QApplication>
#include "deck.h"
#include <QPushButton>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    deck* mydeck = new deck();
    mydeck->shuffleDeck();
    mydeck->dealDeck();
    //mydeck.printStatus();
    for(int i = 0; i < 1; i++){
        //mydeck.playCard();
        //QPushButton *mybuttons[3][8];
        //= w.getButtons();
        /*QPushButton** mybuttonsptr = w.getButtons();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 8; j++){
                cout << &mybuttonsptr[j][i] << endl;
            }
        }*/
        //mydeck.linkCards(mybuttonsptr);
        w.linkCards(mydeck);
        mydeck->drawCard();
        mydeck->checkPoints();
        //mydeck.printStatus();
        mydeck->takeTurns();
    }
    return a.exec();
}

