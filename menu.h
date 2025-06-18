#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>

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
    QListWidget *listWidget;


};
#endif // MENU_H
