#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractTableModel>
#include <QPair>
#include <algorithm>
#include <QDebug>

class ListModel
{
public:
    ListModel() =default;

    void setTableModel(QAbstractTableModel *model, const QString &name);

    QAbstractTableModel* getTableModel(const QString &name);

private:

    QList<QPair<QAbstractTableModel*, QString>> listpair; // указатель на список, изначально null

    QPair<QAbstractTableModel *, QString> pairTableModel;

};

#endif // LISTMODEL_H
