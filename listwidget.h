#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTableView>
#include <QVBoxLayout>
#include <QListWidget>
#include <QVector>



class ListWidget:public QWidget
{
    Q_OBJECT
public:

    ListWidget(QWidget *parent = nullptr);

    void initWidget();

    void initLayout();

    void setModel();

    void addModel(QAbstractItemModel *model);

    void initListWidget();

    void initVector();

    void flushTableWidget();

private:
    QTableView* table;
    QVBoxLayout* box;
    QListWidget* widget;

    QVector<QString> list;

    QAbstractItemModel *model;


};

#endif // LISTWIDGET_H
