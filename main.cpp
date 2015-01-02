#include "mainwindow.h"
#include <QApplication>
#include "deck.h"
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    deck mydeck;
    mydeck.shuffleDeck();
    mydeck.dealDeck();
    //mydeck.printStatus();
    for(int i = 0; i < 4; i++){
        //mydeck.playCard();
        mydeck.drawCard();
        mydeck.checkPoints();
        mydeck.printStatus();
        mydeck.takeTurns();
    }
    return a.exec();
}

