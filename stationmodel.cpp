#include "stationmodel.h"
#include <QDebug>

StationModel::StationModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    // Example: Initial dummy data

}

int StationModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return stations.size();
}

int StationModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return headers.size();
}

QVariant StationModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        return stations[index.row()][index.column()];
    }

    return QVariant();
}

bool StationModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    stations[index.row()][index.column()] = value;

    emit dataChanged(index, index, {role});

    return true;
}

QVariant StationModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal && section < headers.size())
    {
        return headers[section];

    } else if (orientation == Qt::Vertical)
    {
        return section + 1;
    }

    return QVariant();
}

bool StationModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (role != Qt::EditRole)
        return false;

    if (orientation == Qt::Horizontal && section < headers.size())
    {
        headers[section] = value.toString();
        emit headerDataChanged(orientation, section, section);
        return true;
    }

    return false;
}

void StationModel::sort(int column, Qt::SortOrder order)
{
    std::sort(stations.begin(), stations.end(), [column, order](const QVector<QVariant> &a, const QVector<QVariant> &b) {
        return order == Qt::AscendingOrder
            ? a[column] < b[column]
            : a[column] > b[column];
    });

    emit dataChanged(index(0, 0), index(rowCount() - 1, columnCount() - 1));
}
