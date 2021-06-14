#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include<QString>
#include<QEvent>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);
    QString normalImg;
    QString pressImg;
    bool obtausch;
    MyPushButton(QString normalImg,QString pressImg="");
    void zoom1();
    void zoom2();
    void enterEvent(QEvent* );
    void leaveEvent(QEvent*);
    void click_it();

signals:

};

#endif // MYPUSHBUTTON_H
