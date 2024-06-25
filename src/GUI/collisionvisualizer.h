#ifndef COLLISIONVISUALIZER_H
#define COLLISIONVISUALIZER_H

#include <QWidget>

class CollisionVisualizer : public QWidget
{

Q_OBJECT


public:
    CollisionVisualizer();
    ~CollisionVisualizer();

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
private:
    QTimer *timer;
};

#endif // COLLISIONVISUALIZER_H
