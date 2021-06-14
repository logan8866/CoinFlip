#include "chooselevelscene.h"
#include<QPainter>
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include"mypushbutton.h"
#include"mainscene.h"
#include"mylabel.h"
#include<QMouseEvent>
#include"playscene.h"

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(480,882);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("ChooseLevel");
    QMenuBar * bar = new QMenuBar(this);
    this->setMenuBar(bar);
    QMenu * startMenu = new QMenu("satrt",bar);
    bar->addMenu(startMenu);
    QAction * quitAction = new QAction(startMenu);
    quitAction->setText("quit");
    startMenu->addAction(quitAction);
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });
    MyPushButton * returnButton = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    returnButton->setParent(this);
    returnButton->move(this->width()-returnButton->width(),this->height()-returnButton->height());
    connect(returnButton,&MyPushButton::clicked,[=](){
        this->close();
        MainScene * ms = new MainScene();
        ms->show();
    });
    for (int i = 1;i<=20;i++){
        MyPushButton * levelButton = new MyPushButton(":/res/LevelIcon.png");
        levelButton->setParent(this);
        levelButton->move(53.33+2*53.33*((i-1)%4),250+100*((i-1)/4));
        MyLabel * textLabel = new MyLabel(this);
        textLabel->setText(QString::number(i,10));
        textLabel->setAlignment(Qt::AlignCenter);
        textLabel->setFixedSize(levelButton->width(),levelButton->height());
        textLabel->move(53.33+2*53.33*((i-1)%4),250+100*((i-1)/4));
        /*
        //mouse durchclicken
        textLabel->setAttribute(Qt::WA_TransparentForMouseEvents,true);*/
        //neue Methode
        connect(textLabel,&MyLabel::click_label,[=](){
            this->close();
            PlayScene * ps = new PlayScene(i);
            ps->show();
        });
    }
}

void ChooseLevelScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*1.5,pix.height()*1.5);
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);
}

