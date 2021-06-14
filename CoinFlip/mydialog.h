#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QWidget>
#include<QDialog>

class MyDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MyDialog(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    int exec();
    void closeEvent(QCloseEvent *);

signals:
    void closed();
};

#endif // MYDIALOG_H
