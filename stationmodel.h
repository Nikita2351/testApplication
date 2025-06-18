#ifndef STATIONMODEL_H
#define STATIONMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include <QStringList>

class StationModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    StationModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;

private:
    QVector<QVector<QVariant>>     stations = {
        {1, "Central Station", "Downtown"},
        {2, "West Side", "Uptown"},
        {3, "East Point", "Suburbs"}
    };
    QStringList  headers = {"ID", "Name", "Location"};
};

#endif // STATIONMODEL_H
