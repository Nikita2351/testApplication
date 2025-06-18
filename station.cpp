#include "station.h"

quint8 Station::getStnNum() const
{
    return StnNum;
}

void Station::setStnNum(quint8 newStnNum)
{
    StnNum = newStnNum;
}

const QString &Station::getStName() const
{
    return StName;
}

void Station::setStName(const QString &newStName)
{
    StName = newStName;
}

const QString &Station::getStType() const
{
    return StType;
}

void Station::setStType(const QString &newStType)
{
    StType = newStType;
}

const QString &Station::getCodeEsr() const
{
    return CodeEsr;
}

void Station::setCodeEsr(const QString &newCodeEsr)
{
    CodeEsr = newCodeEsr;
}
