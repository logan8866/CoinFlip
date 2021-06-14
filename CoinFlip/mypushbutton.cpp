#include "mypushbutton.h"
#include<QDebug>
#include <QPropertyAnimation>


MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{

}

MyPushButton::MyPushButton(QString normalImg,QString pressImg){
    this->normalImg = normalImg;
    this->pressImg = pressImg;
    this->obtausch = 0;
    QPixmap pix;
    bool ret = pix.load(this->normalImg);
    if (!ret){
        qDebug()<<this->normalImg<<"loading Img fail!";
    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px};");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}

void MyPushButton::enterEvent(QEvent *){
    QPixmap pix;
    bool ret = pix.load(this->pressImg);
    if (!ret){
        return;
    }
    this->setIcon(pix);
    this->obtausch = 1;
}

void MyPushButton::leaveEvent(QEvent *){
    if (this->obtausch==0){
        return;
    }
    QPixmap pix;
    pix.load(this->normalImg);
    this->setIcon(pix);
}

void MyPushButton::zoom1(){
    QPropertyAnimation *animation1 = new QPropertyAnimation(this,"geometry");
    animation1->setDuration(200);
    animation1->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation1->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start(QAbstractAnimation::DeleteWhenStopped);
}

void MyPushButton::zoom2(){
    QPropertyAnimation *animation1 = new QPropertyAnimation(this,"geometry");
    animation1->setDuration(200);
    animation1->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation1->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start(QAbstractAnimation::DeleteWhenStopped);
}

void MyPushButton::click_it(){
    qDebug()<<"clicked";
    return;
}
