#include "mainscene.h"
#include "./ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include "chooselevelscene.h"
#include <QTimer>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    this->setFixedSize(480,882);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("CoinFlip");
    connect(ui->actionquit,&QAction::triggered,[=](){this->close();});
    MyPushButton *startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    ChooseLevelScene * cls = new ChooseLevelScene();

    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);
    connect(startBtn,&MyPushButton::clicked,[=](){
        startBtn->zoom1();
        startBtn->zoom2();
        QTimer::singleShot(300,this,[=](){
            this->close();
            cls->show();
        });

    });

}

void MainScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(15,45,pix.width(),pix.height(),pix);
}

MainScene::~MainScene()
{
    delete ui;
}

