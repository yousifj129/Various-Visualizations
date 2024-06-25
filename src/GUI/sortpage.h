#ifndef SORTPAGE_H
#define SORTPAGE_H

#include <QWidget>
#include <QStackedWidget>

#include "sortvisualizer.h"

namespace Ui {
class SortPage;
}

class SortPage : public QWidget
{
    Q_OBJECT

public:
    explicit SortPage(QStackedWidget *pages, QWidget *parent = nullptr);
    ~SortPage();
    SortVisualizer *sorter;
private:
    Ui::SortPage *ui;
};

#endif // SORTPAGE_H
