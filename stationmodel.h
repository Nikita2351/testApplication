#ifndef STATIONMODEL_H
#define STATIONMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include <QStringList>
#include <QList>

#include <station.h>

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


    void SetList(QVector<Station> station);
private:
    QStringList  headers = {"НомерСтанции", "НазваниеСтанции", "ТипСтанции","КодЕСР"};

    QVector<Station> station;
};

#endif // STATIONMODEL_H
