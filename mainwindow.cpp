#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QPixmap>

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
    mbuttonwhite[0][0] = new QPushButton("", this);
    mbuttonwhite[0][0]->setGeometry(QRect(QPoint(                    buffer, 2 * buffer), QSize(cardsizex, cardsizey)));
    mbuttonwhite[0][0]->setStyleSheet("background-color: white;");
    mbutton[0][0] = new QPushButton("", this);
    mbutton[0][0]->setGeometry(QRect(QPoint(                    buffer, 2 * buffer), QSize(cardsizex, cardsizey)));
    mbutton[0][1] = new QPushButton("", this);
    mbutton[0][1]->setGeometry(QRect(QPoint(    cardsizex + 2 * buffer, 2 * buffer), QSize(cardsizex, cardsizey)));
    mbutton[0][2] = new QPushButton("", this);
    mbutton[0][2]->setGeometry(QRect(QPoint(2 * cardsizex + 3 * buffer, 2 * buffer), QSize(cardsizex, cardsizey)));
    mbutton[0][3] = new QPushButton("", this);
    mbutton[0][3]->setGeometry(QRect(QPoint(3 * cardsizex + 4 * buffer, 2 * buffer), QSize(cardsizex, cardsizey)));
    mbutton[0][4] = new QPushButton("", this);
    mbutton[0][4]->setGeometry(QRect(QPoint(                    buffer, 3 * buffer + cardsizey ), QSize(cardsizex, cardsizey)));
    mbutton[0][5] = new QPushButton("", this);
    mbutton[0][5]->setGeometry(QRect(QPoint(    cardsizex + 2 * buffer, 3 * buffer + cardsizey ), QSize(cardsizex, cardsizey)));
    mbutton[0][6] = new QPushButton("", this);
    mbutton[0][6]->setGeometry(QRect(QPoint(2 * cardsizex + 3 * buffer, 3 * buffer + cardsizey ), QSize(cardsizex, cardsizey)));
    mbutton[0][7] = new QPushButton("", this);
    mbutton[0][7]->setGeometry(QRect(QPoint(3 * cardsizex + 4 * buffer, 3 * buffer + cardsizey ), QSize(cardsizex, cardsizey)));

    mbutton[1][0] = new QPushButton("", this);
    mbutton[1][0]->setGeometry(QRect(QPoint(                    buffer, windowy - 3 * buffer - cardsizey), QSize(cardsizex, cardsizey)));
    mbutton[1][1] = new QPushButton("", this);
    mbutton[1][1]->setGeometry(QRect(QPoint(1 * cardsizex + 2 * buffer, windowy - 3 * buffer - cardsizey), QSize(cardsizex, cardsizey)));
    mbutton[1][2] = new QPushButton("", this);
    mbutton[1][2]->setGeometry(QRect(QPoint(2 * cardsizex + 3 * buffer, windowy - 3 * buffer - cardsizey), QSize(cardsizex, cardsizey)));
    mbutton[1][3] = new QPushButton("", this);
    mbutton[1][3]->setGeometry(QRect(QPoint(3 * cardsizex + 4 * buffer, windowy - 3 * buffer - cardsizey), QSize(cardsizex, cardsizey)));
    mbutton[1][4] = new QPushButton("", this);
    mbutton[1][4]->setGeometry(QRect(QPoint(0 * cardsizex + 1 * buffer, windowy - 4 * buffer - 2 * cardsizey), QSize(cardsizex, cardsizey)));
    mbutton[1][5] = new QPushButton("", this);
    mbutton[1][5]->setGeometry(QRect(QPoint(1 * cardsizex + 2 * buffer, windowy - 4 * buffer - 2 * cardsizey), QSize(cardsizex, cardsizey)));
    mbutton[1][6] = new QPushButton("", this);
    mbutton[1][6]->setGeometry(QRect(QPoint(2 * cardsizex + 3 * buffer, windowy - 4 * buffer - 2 * cardsizey), QSize(cardsizex, cardsizey)));
    mbutton[1][7] = new QPushButton("", this);
    mbutton[1][7]->setGeometry(QRect(QPoint(3 * cardsizex + 4 * buffer, windowy - 4 * buffer - 2 * cardsizey), QSize(cardsizex, cardsizey)));

    mbutton[2][0] = new QPushButton("", this);
    mbutton[2][0]->setGeometry(QRect(QPoint(4 * cardsizex + 7 * buffer, windowy / 2 - cardsizey - buffer/2), QSize(cardsizex, cardsizey)));
    mbutton[2][1] = new QPushButton("", this);
    mbutton[2][1]->setGeometry(QRect(QPoint(5 * cardsizex + 8 * buffer, windowy / 2 - cardsizey - buffer/2), QSize(cardsizex, cardsizey)));
    mbutton[2][2] = new QPushButton("", this);
    mbutton[2][2]->setGeometry(QRect(QPoint(6 * cardsizex + 9 * buffer, windowy / 2 - cardsizey - buffer/2), QSize(cardsizex, cardsizey)));
    mbutton[2][3] = new QPushButton("", this);
    mbutton[2][3]->setGeometry(QRect(QPoint(7 * cardsizex + 10* buffer, windowy / 2 - cardsizey - buffer/2), QSize(cardsizex, cardsizey)));
    mbutton[2][4] = new QPushButton("", this);
    mbutton[2][4]->setGeometry(QRect(QPoint(4 * cardsizex + 7 * buffer, windowy / 2 + buffer/2 ), QSize(cardsizex, cardsizey)));
    mbutton[2][5] = new QPushButton("", this);
    mbutton[2][5]->setGeometry(QRect(QPoint(5 * cardsizex + 8 * buffer, windowy / 2 + buffer/2 ), QSize(cardsizex, cardsizey)));
    mbutton[2][6] = new QPushButton("", this);
    mbutton[2][6]->setGeometry(QRect(QPoint(6 * cardsizex + 9 * buffer, windowy / 2 + buffer/2 ), QSize(cardsizex, cardsizey)));
    mbutton[2][7] = new QPushButton("", this);
    mbutton[2][7]->setGeometry(QRect(QPoint(7 * cardsizex + 10* buffer, windowy / 2 + buffer/2 ), QSize(cardsizex, cardsizey)));

    mbuttondeck = new QPushButton("", this);
    mbuttondeck->setGeometry(QRect(QPoint(11 * cardsizex + 10* buffer, windowy / 2 - cardsizey / 2 ), QSize(cardsizex, cardsizey)));

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 8; j++){
            mbutton[i][j]->setStyleSheet("background-color: white");
            mbutton[i][j]->setStyleSheet("border-image: url(/Users/nicholassaylor/Prog/koikoi/hanafuda/Hanafuda_1-3.svg)  0 0 0 0 stretch stretch;");
        }
    }
    mbuttondeck->setStyleSheet("background-color: white;");

}

MainWindow::~MainWindow()
{
    delete ui;
}
