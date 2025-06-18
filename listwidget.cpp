#include "listwidget.h"

ListWidget::ListWidget(QWidget *parent):QWidget(parent)
{

    initVector();
    initLayout();
    initWidget();
    initListWidget();
}

//иницализация списка виджетов
void ListWidget::initWidget()
{

    table = new QTableView();
    widget = new QListWidget();

    widget->setFlow(QListView::LeftToRight);
    widget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    widget->setFixedHeight(widget->sizeHintForRow(0) + 60);

    box->addWidget(widget);
    box->addWidget(table);
}

//инициализация layout
void ListWidget::initLayout()
{
    box = new QVBoxLayout();
    setLayout(box);
}

//инициализация списка виджетов
void ListWidget::initListWidget()
{
    for(int i=0;i<list.size();i++)
    {
        widget->addItem(list.at(i));
    }
}

//установка модели
void ListWidget::setModel(QAbstractItemModel *model)
{
    table->setModel(model);
}

//инициализация вектора
void ListWidget::initVector()
{
    list.append("Добавить данные");
    list.append("Добавить в закладки");
    list.append("Фильтр");
}

