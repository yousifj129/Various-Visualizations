#ifndef CATEGORYMENU_H
#define CATEGORYMENU_H

#include <QWidget>
#include <QStackedWidget>
#include "sortpage.h"
#include "pathfindingpage.h"
#include "collisiondetectionpage.h"

namespace Ui {
class CategoryMenu;
}

class CategoryMenu : public QWidget
{
    Q_OBJECT

public:
    explicit CategoryMenu(QStackedWidget *pages,QWidget *parent = nullptr);
    ~CategoryMenu();

    SortPage *sortPage;
    PathfindingPage *pathFindingPage;
    CollisionDetectionPage *collisionDetectionPage;

private:
    Ui::CategoryMenu *ui;
};

#endif // CATEGORYMENU_H
