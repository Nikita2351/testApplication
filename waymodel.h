#ifndef WAYMODEL_H
#define WAYMODEL_H

#include <QAbstractTableModel>
#include <QVector>

#include <way.h>

class WayModel:public QAbstractTableModel
{
public:
    WayModel(QObject *parent);
    void setList(QVector<Way> waylist);
private:
    QVector<Way> waylist;

    QVector<QString>  header={"Номер пути","Тип пути","Тип поездок","Тип перевозок"};

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    // QAbstractItemModel interface
public:
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

#endif // WAYMODEL_H
