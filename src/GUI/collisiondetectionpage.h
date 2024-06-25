#ifndef COLLISIONDETECTIONPAGE_H
#define COLLISIONDETECTIONPAGE_H

#include <QWidget>

namespace Ui {
class CollisionDetectionPage;
}

class CollisionDetectionPage : public QWidget
{
    Q_OBJECT

public:
    explicit CollisionDetectionPage(QWidget *parent = nullptr);
    ~CollisionDetectionPage();

private:
    Ui::CollisionDetectionPage *ui;
};

#endif // COLLISIONDETECTIONPAGE_H
