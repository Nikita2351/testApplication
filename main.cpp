#include "menu.h"

#include <QApplication>

//модель
#include <stationmodel.h>

//окна
#include <menu.h>
#include <listwidget.h>
#include <childwindow.h>

//модель(просто класс)
#include <station.h>

//список моделей
#include <listmodel.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString stationName="Станция";

    Station* station =new Station();

    station->setStName("москва товарная");
    station->setStType("1");
    station->setCodeEsr("9865");
    station->setStnNum(1);

    QVector<Station> statinList;

    statinList.append(*station);

    StationModel *model = new StationModel();

     model->SetList(statinList);

    ListModel *modelList = new ListModel();

    modelList->setTableModel(model,stationName);

    Menu *menu = new Menu();

    ListWidget *list = new ListWidget();

    ChildWindow *child = new ChildWindow();

    menu->addStackedWidget(qobject_cast<QWidget*>(child));

    child->setStackedWidget(qobject_cast<QWidget*>(list));

    list->addModel(qobject_cast<QAbstractItemModel*>(modelList->getTableModel("Станция")));

    menu->show();

    //list->flushTableWidget();


    return a.exec();
}
