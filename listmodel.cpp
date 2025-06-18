#include "listmodel.h"

void ListModel::setTableModel(QAbstractTableModel *model, const QString &name)
{
    QPair<QAbstractTableModel *, QString> pairTableModel;

    pairTableModel.first = model;

    pairTableModel.second = name;

    listpair.append(pairTableModel);
}

// Получение модели из списка по имени
QAbstractTableModel* ListModel::getTableModel(const QString &name)
{
    // Ищем элемент в списке по имени (QString в second)
    auto it = std::find_if(listpair.begin(), listpair.end(),
        [&name](const QPair<QAbstractTableModel*, QString> &pair)
            {
                return pair.second == name;
            });

    if (it != listpair.end())
    {
        return it->first;  // возвращаем указатель на модель

    } else {
        return nullptr;    // если не нашли — возвращаем nullptr
    }
}


