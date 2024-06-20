#ifndef SORTVISUALIZER_H
#define SORTVISUALIZER_H

#include <QWidget>
#include <QPainter>
#include <vector>
#include <stdint.h>
#include <QTimer>
#include "../Sorters/abstractsorter.h"
#include "../Sorters/sorter.h"

class SortVisualizer : public QWidget
{
    Q_OBJECT
public:
    SortVisualizer(QWidget *parent = nullptr);
    ~SortVisualizer();

public slots:
    void changeSortMethod(Sorter method);
    void startVisualization();
    void stopVisualization();
    void randomizeValues();
    void changeSize(uint16_t s);
    void reset();
    void sortStep();
protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
private:
    float colWidth;
    float colHeight;
    uint16_t MINSIZE=1;
    uint16_t maxValue;
    std::vector<uint16_t> values;
    QTimer *timer;
    int16_t compared1;
    int16_t compared2;
    void resizeColumns();
    AbstractSorter *sorter;

};

#endif // SORTVISUALIZER_H
