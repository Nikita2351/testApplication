#ifndef WAY_H
#define WAY_H

#include <QString>


class Way
{
public:    
    Way()=default;

    int getIdWay() const;
    void setIdWay(int newIdWay);

    int getTypeWay() const;

    void setTypeWay(int newTypeWay);

    int getTypeTravel() const;
    void setTypeTravel(int newTypeTravel);

private:
    int idWay;
    int TypeWay;
    int TypeTravel;
};

#endif // WAY_H
