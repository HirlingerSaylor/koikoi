#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "card.h"
#include "deck.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //QPushButton** getButtons();
    void linkCards(deck*);
private:
    Ui::MainWindow *ui;
    QPushButton* mbutton[3][8];
    //QPushButton* mbuttonwhite[3][8];
    QPushButton* mbuttondeck;
};

#endif // MAINWINDOW_H
