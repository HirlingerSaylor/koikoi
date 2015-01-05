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
    //mydeck->printStatus();
    w.linkCards(mydeck);

    return a.exec();

}

