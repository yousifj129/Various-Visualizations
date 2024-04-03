#ifndef CATEGORYMENU_H
#define CATEGORYMENU_H

#include <QWidget>

namespace Ui {
class CategoryMenu;
}

class CategoryMenu : public QWidget
{
    Q_OBJECT

public:
    explicit CategoryMenu(QWidget *parent = nullptr);
    ~CategoryMenu();

private:
    Ui::CategoryMenu *ui;
};

#endif // CATEGORYMENU_H
