#include "listwidget.h"

ListWidget::ListWidget(QWidget *parent):QWidget(parent)
{

    initLayout();
    initList();
}

//иницализация списка виджетов
void ListWidget::initList()
{

    table = new QTableView();

    box->addWidget(table);
}

//инициализация layout
void ListWidget::initLayout()
{
    box = new QVBoxLayout();
    setLayout(box);
}

void ListWidget::setModel(QAbstractItemModel *model)
{
    table->setModel(model);
}
