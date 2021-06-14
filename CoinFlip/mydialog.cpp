#include "mydialog.h"
#include<QPainter>
#include<QDebug>

MyDialog::MyDialog(QWidget *parent) : QDialog(parent)
{

}

void MyDialog::paintEvent(QPaintEvent *event){
    QPixmap pix;
    pix.load(":/res/LevelCompletedDialogBg.png");
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    this->resize(241,84);
}

int MyDialog::exec(){
    return QDialog::exec();
}

void MyDialog::closeEvent(QCloseEvent *){
    qDebug()<<"closed";
    emit this->closed();
}


