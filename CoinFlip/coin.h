#ifndef COIN_H
#define COIN_H

#include <QWidget>
#include<QPushButton>
#include<QString>
#include<QVector>
#include<QTimer>

class Coin : public QPushButton
{
    Q_OBJECT
public:
    explicit Coin(int status,QWidget *parent = nullptr);
    Coin(QWidget *parent = nullptr);
    int status;
    QString coinImg_1 = ":/res/Coin0001.png";
    QString coinImg_2 = ":/res/Coin0002.png";
    QString coinImg_3 = ":/res/Coin0003.png";
    QString coinImg_4 = ":/res/Coin0004.png";
    QString coinImg_5 = ":/res/Coin0005.png";
    QString coinImg_6 = ":/res/Coin0006.png";
    QString coinImg_7 = ":/res/Coin0007.png";
    QString coinImg_8 = ":/res/Coin0008.png";
    QVector<QString> *coinImg_all;
    int x;
    int y;
    int clicked_flag=0;
    int max = 8;
    int min = 1;
    QTimer *timer1 = new QTimer(this);
    QTimer *timer2 = new QTimer(this);
    void convers();

signals:

};

#endif // COIN_H
