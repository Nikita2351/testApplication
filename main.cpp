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


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Station* station =new Station();

    Menu *menu = new Menu();

    ListWidget *list = new ListWidget();

    ChildWindow *child = new ChildWindow();

    StationModel *model = new StationModel();

    menu->addStackedWidget(qobject_cast<QWidget*>(child));

    child->setStackedWidget(qobject_cast<QWidget*>(list));

    list->setModel(qobject_cast<QAbstractItemModel*>(model));

    menu->show();

    return a.exec();
}
