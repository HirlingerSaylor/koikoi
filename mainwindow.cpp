#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QPixmap>
#include <iostream>
#include "deck.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setStyleSheet("MainWindow {background-image: url(/Users/nicholassaylor/Prog/koikoi/hokusai1834a.jpg);}");
    int windowx = 1150;
    int windowy = 750;
    this->setWindowTitle("koikoi");
    this->setFixedSize(windowx, windowy);
    //this->setStyleSheet("background-color: black;");
    //this->setStyleSheet("background: url(/Users/nicholassaylor/Prog/koikoi/Mount_Fuji_seen_throught_cherry_blossom.jpg); ");
    int cardsizex = 85;
    int cardsizey = 120;
    int buffer    = 10;
    int xplace[3][8] = { { 0 * cardsizex + 1 * buffer, 1 * cardsizex + 2 * buffer,
                           2 * cardsizex + 3 * buffer, 3 * cardsizex + 4 * buffer,
                           0 * cardsizex + 1 * buffer, 1 * cardsizex + 2 * buffer,
                           2 * cardsizex + 3 * buffer, 3 * cardsizex + 4 * buffer},
                         { 0 * cardsizex + 1 * buffer, 1 * cardsizex + 2 * buffer,
                           2 * cardsizex + 3 * buffer, 3 * cardsizex + 4 * buffer,
                           0 * cardsizex + 1 * buffer, 1 * cardsizex + 2 * buffer,
                           2 * cardsizex + 3 * buffer, 3 * cardsizex + 4 * buffer},
                         { 4 * cardsizex + 7 * buffer, 5 * cardsizex + 8 * buffer,
                           6 * cardsizex + 9 * buffer, 7 * cardsizex + 10* buffer,
                           4 * cardsizex + 7 * buffer, 5 * cardsizex + 8 * buffer,
                           6 * cardsizex + 9 * buffer, 7 * cardsizex + 10* buffer} };
    int yplace[3][8] = { { 2 * buffer, 2 * buffer, 2 * buffer, 2 * buffer,
                           3 * buffer + cardsizey, 3 * buffer + cardsizey,
                           3 * buffer + cardsizey, 3 * buffer + cardsizey},
                         {windowy - 3 * buffer - 1 * cardsizey, windowy - 3 * buffer - 1 * cardsizey,
                          windowy - 3 * buffer - 1 * cardsizey, windowy - 3 * buffer - 1 * cardsizey,
                          windowy - 4 * buffer - 2 * cardsizey, windowy - 4 * buffer - 2 * cardsizey,
                          windowy - 4 * buffer - 2 * cardsizey, windowy - 4 * buffer - 2 * cardsizey},
                         {windowy / 2 - cardsizey - buffer/2, windowy / 2 - cardsizey - buffer/2,
                          windowy / 2 - cardsizey - buffer/2, windowy / 2 - cardsizey - buffer/2,
                          windowy / 2             + buffer/2, windowy / 2             + buffer/2,
                          windowy / 2             + buffer/2, windowy / 2             + buffer/2} };


    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 8; j++){
            mbutton[i][j] = new QPushButton("", this);
            mbutton[i][j]->setGeometry(QRect(QPoint(xplace[i][j], yplace[i][j]), QSize(cardsizex, cardsizey)));
            mbutton[i][j]->setStyleSheet("background-color: maroon");
            //mbutton[i][j]->setStyleSheet("border-image: url(/Users/nicholassaylor/Prog/koikoi/hanafuda/mod_Hanafuda_13-4.svg)  0 0 0 0 stretch stretch;");
        }
    }

    mbuttondeck = new QPushButton("", this);
    mbuttondeck->setGeometry(QRect(QPoint(11 * cardsizex + 10* buffer, windowy / 2 - cardsizey / 2 ), QSize(cardsizex, cardsizey)));

    mbuttondeck->setStyleSheet("background-color: maroon;");

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*QPushButton** MainWindow::getButtons(){
    cout << "These are the originals: " << endl << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 8; j++){
            cout << mbutton[i][j] << endl;
        }
    }
    cout << endl << endl;

    //QPushButton array2D[3][8];
    //array2D = (QPushButton**)mbutton;
    //return array2D;
    return *mbutton;
}*/

void MainWindow::linkCards(deck* mydeck){
    int i = 0;
    int j[3] = {0, 0, 0};
    card** mycards = (card**)mydeck->getCards();
    int* myqueue = mydeck->getQueue();
    for( int k = 0; k < 48; k++){
        int i       = mycards[myqueue[k]]->getOwner();
        int mymonth = mycards[myqueue[k]]->getMonth();
        int myvalue = mycards[myqueue[k]]->getValue();
        string myvaluestr;
        string mymonthstr;

        QString mycommand = "border-image: url(/Users/nicholassaylor/Prog/koikoi/hanafuda/mod_Hanafuda_";
        mycommand += QString::number(mymonth);
        mycommand += "-";
        mycommand += QString::number(myqueue[k] % 4 + 1);
        mycommand += ".svg)  0 0 0 0 stretch stretch;";
        //QString::number(num);

        //QString qstr = QString::fromStdString(mycommand);
        //cout << mycommand.toStdString() << endl;
        if( i <= 3 && i > 0){
            int ind = 0;
            if( i == 3 ){
                ind = 0;
            }else{
                ind = i;
            }
            //cout << mycommand << endl;
            cout << j[ind] << ", " << i << endl;
            //mybuttons[i][j[i]].setStyleSheet(qstr);
            mbutton[ind][j[ind]]->setStyleSheet(mycommand);
            j[ind]++;
        }
    }
}
