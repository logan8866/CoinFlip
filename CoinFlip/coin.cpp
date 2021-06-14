#include "coin.h"
#include<QPixmap>
#include<QDebug>


Coin::Coin(int status,QWidget *parent) : QPushButton(parent)
{
    this->status = status;
    QPixmap pix;
    if (status==1){
        pix.load(this->coinImg_1);
    }
    if (status==0){
        pix.load(this->coinImg_8);
    }
    this->setIcon(pix);
    this->setFixedSize(pix.width(),pix.height());
    this->setIconSize(QSize(pix.width(),pix.height()));
    this->setStyleSheet("QPushButton{border:0px};");
    this->coinImg_all = new QVector<QString>();
    this->coinImg_all->append(this->coinImg_1);
    this->coinImg_all->append(this->coinImg_2);
    this->coinImg_all->append(this->coinImg_3);
    this->coinImg_all->append(this->coinImg_4);
    this->coinImg_all->append(this->coinImg_5);
    this->coinImg_all->append(this->coinImg_6);
    this->coinImg_all->append(this->coinImg_7);
    this->coinImg_all->append(this->coinImg_8);
    connect(timer1,&QTimer::timeout,[=]{
        QPixmap pix;
        if (this->min==8){
            QPixmap pix;
            pix.load(coinImg_all->at(this->min-1));
            this->setFixedSize(pix.width(),pix.height());
            this->setIconSize(QSize(pix.width(),pix.height()));
            this->setStyleSheet("QPushButton{border:0px};");
            this->setIcon(pix);
            this->status = 0;
            this->timer1->stop();
            //qDebug()<<this->min<<coinImg_all->at(this->min-1);
            this->min=1;
            return;
        }
        pix.load(coinImg_all->at(this->min-1));
        this->setFixedSize(pix.width(),pix.height());
        this->setIconSize(QSize(pix.width(),pix.height()));
        this->setStyleSheet("QPushButton{border:0px};");
        this->setIcon(pix);
        //qDebug()<<this->min<<coinImg_all->at(this->min-1);
        this->min++;
    });
    connect(timer2,&QTimer::timeout,[=]{
        QPixmap pix;
        if (this->max==1){
            QPixmap pix;
            pix.load(coinImg_all->at(this->max-1));
            this->setFixedSize(pix.width(),pix.height());
            this->setIconSize(QSize(pix.width(),pix.height()));
            this->setStyleSheet("QPushButton{border:0px};");
            this->setIcon(pix);
            this->timer2->stop();
            this->max = 8;
            return;
        }
        pix.load(coinImg_all->at(this->max-1));
        this->setFixedSize(pix.width(),pix.height());
        this->setIconSize(QSize(pix.width(),pix.height()));
        this->setStyleSheet("QPushButton{border:0px};");
        this->setIcon(pix);
        this->max--;
    });

}

void Coin::convers(){
    if(this->status==1){
        this->timer1->start(50);
        this->status = 0;
    }
    else if(this->status==0){
        this->timer2->start(50);
        this->status = 1;
    }
}

Coin::Coin(QWidget *parent):QPushButton(parent){

}
