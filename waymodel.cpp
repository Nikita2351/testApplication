#include "waymodel.h"


WayModel::WayModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    // Здесь можно добавить инициализацию
}


void WayModel::setList(QVector<Way> waylist)
{
    this->waylist = waylist;
}

int WayModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
    {
        return 0;
    }
    return waylist.size();
}

int WayModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
    {
        return 0;
    }
    return header.size();
}

QVariant WayModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
}

bool WayModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid() || role != Qt::EditRole)
    {
        return false;
    }

    Way &way = waylist[index.row()];

    switch(index.column())
    {
        case 0:way.setIdWay(value.toUInt());break;

        case 1:way.setTypeWay(value.toUInt()); break;

        case 2:way.setTypeTravel(value.toUInt());break;

        default:return false;
    }
}

QVariant WayModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if(orientation == Qt::Horizontal && section < header.size())
    {
        return header[section];
    }

    return QVariant();
}



bool WayModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{

    if(role != Qt::EditRole)
    {
        return false;
    }

    if(orientation == Qt::Horizontal && section <header.size())
    {
        header[section] = value.toString();
        emit headerDataChanged(orientation,section,section);
    }

    return false;
}
