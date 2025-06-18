#ifndef CHILDWINDOW_H
#define CHILDWINDOW_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QScrollArea>
#include <QListWidget>
#include <QLabel>
#include <QWidgetItem>

class ChildWindow:public QWidget
{
    Q_OBJECT
public:
    ChildWindow();
private:
    void AddLayout();
    void initWidget();
public:
    void setStackedWidget(QWidget *widget);
private:
    void initList();
     void initListWidget();
private:
    QVBoxLayout *layout;

    QStackedWidget *widget;

    QScrollArea *area;

    QVector<QString> *stringlist;

    QListWidget *listWidget;

};

#endif // CHILDWINDOW_H
