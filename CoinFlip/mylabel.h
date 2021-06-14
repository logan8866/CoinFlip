#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include<QtWidgets>
#include<QMouseEvent>

class MyLabel:public QLabel
{
    Q_OBJECT
public:
    MyLabel(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *ev);

signals:
    void click_label();
};

#endif // MYLABEL_H
