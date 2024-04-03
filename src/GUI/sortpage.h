#ifndef SORTPAGE_H
#define SORTPAGE_H

#include <QWidget>

namespace Ui {
class SortPage;
}

class SortPage : public QWidget
{
    Q_OBJECT

public:
    explicit SortPage(QWidget *parent = nullptr);
    ~SortPage();

private:
    Ui::SortPage *ui;
};

#endif // SORTPAGE_H
