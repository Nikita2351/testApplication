#include "menu.h"


Menu::Menu(QWidget *parent)
    : QWidget(parent)
{
    initLayout();
    setLayout(box);
    box->addLayout(vboxRigth);
    box->addLayout(vboxLeft);
    initWidget();
}

Menu::~Menu()
{

}

//инициализация виджетов
void Menu::initWidget()
{
    stacked = new QStackedWidget();
    listWidget = new QListWidget();
    vboxLeft->addWidget(stacked);
    vboxRigth->addWidget(listWidget);
}

//инициализация layout
void Menu::initLayout()
{
    box = new QHBoxLayout();
    vboxRigth = new QVBoxLayout();
    vboxLeft = new QVBoxLayout();
}

//добавление окна
void Menu::addStackedWidget(QWidget *widget)
{
    stacked->addWidget(widget);
}

