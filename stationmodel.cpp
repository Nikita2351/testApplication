#include "stationmodel.h"
#include <QDebug>

StationModel::StationModel(QObject *parent)
    : QAbstractTableModel(parent){}

//установка списка
int StationModel::SetList(QList<Station> station)
{
    this->station = station;
}

//количество строк
int StationModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return station.size();
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

    const Station &st = station.at(index.row());

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        switch (index.column())
        {
            case 0: return st.getStnNum();
            case 1: return st.getStName();
            case 2: return st.getStType();
            case 3: return st.getCodeEsr();
            default: return QVariant();
        }
    }

    return QVariant();
}

bool StationModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    Station &st = station[index.row()];

    switch (index.column())
    {
            case 0: st.setStnNum(value.toUInt()); break;

            case 1: st.setStName(value.toString()); break;

            case 2: st.setStType(value.toString()); break;

            case 3: st.setCodeEsr(value.toString()); break;

        default: return false;
    }
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

    }
    else if (orientation == Qt::Vertical)
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
    std::sort(station.begin(), station.end(), [column, order](const QVector<QVariant> &a, const QVector<QVariant> &b) {
        return order == Qt::AscendingOrder
            ? a[column] < b[column]
            : a[column] > b[column];
    });

    emit dataChanged(index(0, 0), index(rowCount() - 1, columnCount() - 1));
}
