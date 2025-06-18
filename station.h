#ifndef STATION_H
#define STATION_H

#include <QString>


class Station
{
public:
    Station()=default;
    quint8 getStnNum() const;
    void setStnNum(quint8 newStnNum);

    const QString &getStName() const;
    void setStName(const QString &newStName);

    const QString &getStType() const;
    void setStType(const QString &newStType);

    const QString &getCodeEsr() const;
    void setCodeEsr(const QString &newCodeEsr);

private:
    quint8 StnNum;

    QString StName;

    QString StType;

    QString CodeEsr;
};

#endif // STATION_H
