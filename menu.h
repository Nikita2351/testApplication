#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>

#include <QTreeView>
#include <QStandardItemModel>
#include <QTreeWidget>
#include <QLabel>

class Menu : public QWidget
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();
    void addStackedWidget(QWidget *widget);
    void initWidget();
    void initLayout();
private:
    QHBoxLayout* box;
    QVBoxLayout* vboxRigth;
    QVBoxLayout* vboxLeft;
    QStackedWidget* stacked;
    QTreeWidget *treeWidget ;
private:




};
#endif // MENU_H
