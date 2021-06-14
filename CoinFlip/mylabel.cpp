#include "mylabel.h"
#include<QDebug>

MyLabel::MyLabel(QWidget *parent):QLabel(parent)
{

}

void MyLabel::mousePressEvent(QMouseEvent *){
    qDebug()<<"press";
    emit this->click_label();
}

