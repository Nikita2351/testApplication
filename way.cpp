#include "way.h"

int Way::getIdWay() const
{
    return idWay;
}

void Way::setIdWay(int newIdWay)
{
    idWay = newIdWay;
}

int Way::getTypeWay() const
{
    return TypeWay;
}

void Way::setTypeWay(int newTypeWay)
{
    TypeWay = newTypeWay;
}

int Way::getTypeTravel() const
{
    return TypeTravel;
}

void Way::setTypeTravel(int newTypeTravel)
{
    TypeTravel = newTypeTravel;
}
