#include "playscene.h"
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QPainter>
#include"mypushbutton.h"
#include<QLabel>
#include"chooselevelscene.h"
#include<QString>
#include<QFont>
#include"coin.h"
#include"dataconfig.h"
#include<QDebug>
#include"mydialog.h"

PlayScene::PlayScene(QWidget *parent){

}

PlayScene::PlayScene(int level,QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(480,882);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("PlayScene");
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
        ChooseLevelScene * cls = new ChooseLevelScene();
        cls->show();
    });
    this->level = level;
    QLabel *level_label = new QLabel(this);
    QString level_text = "Level "+QString::number(this->level);
    QFont font;
    font.setPointSize(20);
    level_label->setFont(font);
    level_label->setText(level_text);
    level_label->setFixedSize(100,50);
    level_label->move(30,50);
    for(int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            QLabel *bg_coin = new QLabel(this);
            bg_coin->setGeometry(0,0,50,50);
            bg_coin->setPixmap(QPixmap(":/res/BoardNode.png"));
            bg_coin->move(140+i*52,350+j*52);
        }
    }
    DataConfig * dfg = new DataConfig();
    Coin * coin_all[4][4];
    for(int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            Coin *coin = new Coin(dfg->map[0][this->level].at(i).at(j),this);
            coin->move(140+i*52,350+j*52);
            coin->x = i;
            coin->y = j;
            coin_all[i][j] = coin;

        }
    }
    for(int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            connect(coin_all[i][j],&QPushButton::clicked,[=]{
                if (coin_all[i][j]->clicked_flag==1){
                    return;
                }
                coin_all[i][j]->clicked_flag = 1;
                coin_all[i][j]->convers();
                dfg->map[0][this->level][i][j] = coin_all[i][j]->status;
                if (i<3&&i>0){
                    coin_all[i-1][j]->convers();
                    dfg->map[0][this->level][i-1][j] = coin_all[i-1][j]->status;
                    coin_all[i+1][j]->convers();
                    dfg->map[0][this->level][i+1][j] = coin_all[i+1][j]->status;
                }
                if (i==3){
                    coin_all[i-1][j]->convers();
                    dfg->map[0][this->level][i-1][j] = coin_all[i-1][j]->status;
                }
                if (i==0){
                    coin_all[i+1][j]->convers();
                    dfg->map[0][this->level][i+1][j] = coin_all[i+1][j]->status;
                }
                if (j<3&&j>0){
                    coin_all[i][j-1]->convers();
                    dfg->map[0][this->level][i][j-1] = coin_all[i][j-1]->status;
                    coin_all[i][j+1]->convers();
                    dfg->map[0][this->level][i][j+1] = coin_all[i][j+1]->status;
                }
                if(j==3){
                    coin_all[i][j-1]->convers();
                    dfg->map[0][this->level][i][j-1] = coin_all[i][j-1]->status;
                }
                if (j==0){
                    coin_all[i][j+1]->convers();
                    dfg->map[0][this->level][i][j+1] = coin_all[i][j+1]->status;
                }
                this->succeed_flag = 1;
                for(int i=0;i<4;i++){
                    for (int j=0;j<4;j++){
                        if (dfg->map[0][this->level][i][j]==0){
                            this->succeed_flag = 0;
                            break;
                        }
                    }
                    if (this->succeed_flag==0){
                        break;
                    }
                }
                if (this->succeed_flag == 1){
                    MyDialog *dl = new MyDialog(this);
                    connect(dl,&MyDialog::closed,[=]{
                        this->close();
                        ChooseLevelScene *cls = new ChooseLevelScene();
                        cls->show();
                    });
                    dl->exec();
                }
                coin_all[i][j]->clicked_flag = 0;
            });
        }
    }

}

void PlayScene::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
