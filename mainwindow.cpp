#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QPixmap>
#include <iostream>
#include "deck.h"
#include <cmath>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setStyleSheet("MainWindow {background-image: url(/Users/nicholassaylor/Prog/koikoi/hokusai1834a.jpg);}");
    mapper = new QSignalMapper();
    int windowx = 1200;
    int windowy = 750;
    this->setWindowTitle("koikoi");
    this->setFixedSize(windowx, windowy);
    int cardsizex = 85;
    int cardsizey = 120;
    int buffer    = 10;
    int xplacehand[2][8];
    int yplacehand[2][8];
    int xplacecapture[32];
    int yplacecapture[2];
    int xplacefield[12];
    int yplacefield[12];
    for( int i = 0; i < 2; i++){
        for(int j = 0; j < 8; j++){
            xplacehand[i][j] = ( ( j % 4 ) * cardsizex + ( j % 4 + 1 ) * buffer );
            if( i == 0 && j < 4 )
                yplacehand[i][j] = 2 * buffer;
            if( i == 0 && j >=4 )
                yplacehand[i][j] = 3 * buffer + cardsizey;
            if( i == 1 && j < 4 )
                yplacehand[i][j] = windowy - 3 * buffer - 1 * cardsizey;
            if( i == 1 && j >=4 )
                yplacehand[i][j] = windowy - 4 * buffer - 2 * cardsizey;
        }
    }
    for(int i = 0; i < 12; i++){
        xplacefield[i] = ( 4 + floor( i / 2 ) ) * cardsizex + ( 7 + floor( i / 2 ) ) * buffer;
        if( i % 2 == 0 ){
            yplacefield[i] = windowy / 2 - cardsizey - buffer/2;
        }else{
            yplacefield[i] = windowy / 2             + buffer/2;
        }
    }
    float div = ( 7 * cardsizex + 7 * buffer ) / 31.;
    for(int i = 0; i < 32; i++){
        xplacecapture[i] = 4 * cardsizex + 7 * buffer + i * div;
    }
    yplacecapture[0] = 2.5 * buffer + 0.5 * cardsizey;
    yplacecapture[1] = windowy - 3.5 * buffer - 1.5 * cardsizey;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 8; j++){
            mbuttonhand[i][j] = new QPushButton("", this);
            mbuttonhand[i][j]->setGeometry(QRect(QPoint(xplacehand[i][j], yplacehand[i][j]), QSize(cardsizex, cardsizey)));
            mbuttonhand[i][j]->setStyleSheet("background-color: maroon");
        }
    }

    for(int i = 0; i < 12; i++){
        mbuttonfield[i] = new QPushButton("", this);
        mbuttonfield[i]->setGeometry(QRect(QPoint(xplacefield[i], yplacefield[i]), QSize(cardsizex, cardsizey)));
        mbuttonfield[i]->setStyleSheet("background-color: maroon");
        mbuttonfield[i]->setVisible(false);
        mbuttonfield[i]->setEnabled(false);
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 32; j++){
            mbuttoncapture[i][j] = new QPushButton("", this);
            mbuttoncapture[i][j]->setGeometry(QRect(QPoint(xplacecapture[j], yplacecapture[i]), QSize(cardsizex, cardsizey)));
            mbuttoncapture[i][j]->setStyleSheet("background-color: maroon");
            mbuttoncapture[i][j]->setVisible(false);
            mbuttoncapture[i][j]->setEnabled(false);
        }
    }

    mbuttondeck = new QPushButton("", this);
    mbuttondeck->setGeometry(QRect(QPoint(11 * cardsizex + 10* buffer, windowy / 2 - cardsizey / 2 ), QSize(cardsizex, cardsizey)));
    mbuttondeck->setStyleSheet("background-color: maroon;");
    mbuttonplayed = new QPushButton("", this);
    mbuttonplayed->setGeometry(QRect(QPoint(1.5 * cardsizex + 2.5 * buffer, windowy / 2 - cardsizey / 2 ), QSize(cardsizex, cardsizey)));
    mbuttonplayed->setStyleSheet("background-color: maroon;");
    mbuttonplayed->setVisible(false);
    mbuttonplayed->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::linkCards(deck* mydeck){
    int j[6] = {0, 0, 0, 0, 0, 0};
    card** mycards = (card**)mydeck->getCards();
    int* myqueue = mydeck->getQueue();
    for( int k = 0; k < 48; k++){
        int i     = mycards[myqueue[k]]->getOwner();
        int mymonth = mycards[myqueue[k]]->getMonth();
        int myvalue = mycards[myqueue[k]]->getValue();
        string myvaluestr;
        string mymonthstr;
        QString mycommand = " border-image: url(/Users/nicholassaylor/Prog/koikoi/hanafuda/mod_Hanafuda_";
        mycommand += QString::number(mymonth);
        mycommand += "-";
        mycommand += QString::number(myqueue[k] % 4 + 1);
        mycommand += ".svg)  0 0 0 0 stretch stretch;";
        if( i < 2 ){
            mbuttonhand[i][j[i]]->setStyleSheet(mycommand);
            connect(mbuttonhand[i][j[i]], SIGNAL(clicked()), mapper, SLOT(map()));
            mapper->setMapping(mbuttonhand[i][j[i]], QString::number( ( i + 1 ) * 100 + j[i]) + mycommand );
            j[i]++;
        }else if( i == 4 ){
            mbuttonfield[j[i]]->setStyleSheet(mycommand);
            mbuttonfield[j[i]]->setVisible(true);
            mbuttonfield[j[i]]->setEnabled(true);
            j[i]++;
        }
    }
    connect(mapper, SIGNAL(mapped(QString)), this, SLOT(swapButtons(QString)));
}

void MainWindow::swapButtons(QString mycommand){
    QString aleft = mycommand.left(3);
    QString aright= mycommand.mid(4);
    int     leftint = aleft.toInt() - 100;
    int     i = floor(leftint / 100.);
    int     j = leftint - 100 * i;
    mbuttonhand[i][j]->setVisible(false);
    mbuttonhand[i][j]->setEnabled(false);
    mbuttonplayed->setStyleSheet(aright);
    mbuttonplayed->setVisible(true);
    mbuttonplayed->setEnabled(true);
}
