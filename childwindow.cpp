#include "childwindow.h"

ChildWindow::ChildWindow()
{
     initList();

     AddLayout();

    initWidget();

    initListWidget();

    setLayout(layout);

}

//добавление layout
void ChildWindow::AddLayout()
{
    layout = new QVBoxLayout();
}

//добавление виджетов
void ChildWindow::initWidget()
{
    widget = new QStackedWidget();

    listWidget = new QListWidget();

    listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // Настроить режим отображения (необязательно)
    listWidget->setFlow(QListView::TopToBottom);  // По умолчанию

    listWidget->setFlow(QListView::LeftToRight);


    // Уменьшаем высоту до минимального нужного размера
    listWidget->setFixedHeight(listWidget->sizeHintForRow(0) + 60); // немного запас сверху-снизу


    layout->addWidget(listWidget);

    layout->addWidget(widget);
}

//добавление под окна для виджета
void ChildWindow::setStackedWidget(QWidget *widget)
{
    this->widget->addWidget(widget);
}

//инициализация списка
void ChildWindow::initList()
{
    stringlist = new QVector<QString>;

    stringlist->append("Список станций");
    stringlist->append("Список перегонов");
    stringlist->append("Список стыковых  пунктов");
    stringlist->append("СЦБ");
    stringlist->append("норма и порядок закрепления поездов ");
    stringlist->append("телефонный справочник");
}

//заполнение scrollarea
void ChildWindow::initListWidget()
{
    for(int i =0 ;i<stringlist->size();i++)
    {
        listWidget->addItem(stringlist->at(i));
    }
}



