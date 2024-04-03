#include "sortpage.h"
#include "ui_sortpage.h"

SortPage::SortPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SortPage)
{
    ui->setupUi(this);
}

SortPage::~SortPage()
{
    delete ui;
}
