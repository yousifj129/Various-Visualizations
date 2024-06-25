#ifndef COLLISIONDETECTIONPAGE_H
#define COLLISIONDETECTIONPAGE_H

#include <QWidget>
#include <QStackedWidget>

namespace Ui {
class CollisionDetectionPage;
}

class CollisionDetectionPage : public QWidget
{
    Q_OBJECT

public:
    explicit CollisionDetectionPage(QStackedWidget *pages, QWidget *parent = nullptr);
    ~CollisionDetectionPage();

private:
    Ui::CollisionDetectionPage *ui;
};

#endif // COLLISIONDETECTIONPAGE_H
