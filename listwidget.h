#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTableView>
#include <QVBoxLayout>



class ListWidget:public QWidget
{
    Q_OBJECT
public:

    ListWidget(QWidget *parent = nullptr);

    void initList();
    void initLayout();
    void setModel(QAbstractItemModel *model);
private:
    QTableView* table;
    QVBoxLayout* box;




};

#endif // LISTWIDGET_H
