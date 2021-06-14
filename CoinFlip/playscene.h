#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int level,QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    int level;
    int succeed_flag = 0;

signals:

};

#endif // PLAYSCENE_H
