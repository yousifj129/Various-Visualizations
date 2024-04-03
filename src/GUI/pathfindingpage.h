#ifndef PATHFINDINGPAGE_H
#define PATHFINDINGPAGE_H

#include <QWidget>

namespace Ui {
class PathfindingPage;
}

class PathfindingPage : public QWidget
{
    Q_OBJECT

public:
    explicit PathfindingPage(QWidget *parent = nullptr);
    ~PathfindingPage();

private:
    Ui::PathfindingPage *ui;
};

#endif // PATHFINDINGPAGE_H
