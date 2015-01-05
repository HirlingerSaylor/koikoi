#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "card.h"
#include "deck.h"
#include <QSignalMapper>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void linkCards(deck*);
private slots:
    void swapButtons(QString mycommand);
private:
    Ui::MainWindow *ui;
    QPushButton* mbuttonhand[2][8];
    QPushButton* mbuttoncapture[2][32];
    QPushButton* mbuttonfield[12];
    QPushButton* mbuttondeck;
    QPushButton* mbuttonplayed;
    QSignalMapper* mapper;
};

#endif // MAINWINDOW_H
