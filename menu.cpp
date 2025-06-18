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
    stacked =    new QStackedWidget();
    treeWidget = new QTreeWidget(this);

    treeWidget->setMaximumWidth(200); // максимальная ширина

    vboxLeft->addWidget(stacked);
    vboxRigth->addWidget(treeWidget);

    treeWidget->setHeaderHidden(true); // скрываем заголовок

    // --- Первый корневой элемент ---
    QTreeWidgetItem *infoItem = new QTreeWidgetItem(treeWidget);
    infoItem->setSizeHint(0, QSize(200, 40)); // задаём высоту
    QLabel *infoLabel = new QLabel("Оперативно-справочная информация");
    infoLabel->setWordWrap(true);
    treeWidget->setItemWidget(infoItem, 0, infoLabel);

    // --- Дочерние элементы ---
    auto createChild = [&](QTreeWidgetItem *parent, const QString &text) {
        QTreeWidgetItem *item = new QTreeWidgetItem(parent);
        item->setSizeHint(0, QSize(200, 40));
        QLabel *label = new QLabel(text);
        label->setWordWrap(true);
        treeWidget->setItemWidget(item, 0, label);
    };

    createChild(infoItem, "Список станций");
    createChild(infoItem, "Список перегонов");
    createChild(infoItem, "Список стыковых пунктов");
    createChild(infoItem, "СЦБ");
    createChild(infoItem, "Норма крепления поездов");
    createChild(infoItem, "Телефонный справочник");

    // --- Второй корневой элемент ---
    QTreeWidgetItem *paramsItem = new QTreeWidgetItem(treeWidget);
    paramsItem->setSizeHint(0, QSize(200, 40));
    QLabel *paramsLabel = new QLabel("Параметры");
    paramsLabel->setWordWrap(true);
    treeWidget->setItemWidget(paramsItem, 0, paramsLabel);

    // --- Раскрываем всё ---
    treeWidget->expandAll();
}

//инициализация layout
void Menu::initLayout()
{
    box =       new QHBoxLayout();
    vboxRigth = new QVBoxLayout();
    vboxLeft =  new QVBoxLayout();
}

//добавление окна
void Menu::addStackedWidget(QWidget *widget)
{
    stacked->addWidget(widget);
}

