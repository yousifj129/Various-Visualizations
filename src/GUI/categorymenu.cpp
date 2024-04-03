#include "categorymenu.h"
#include "ui_categorymenu.h"

CategoryMenu::CategoryMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CategoryMenu)
{
    ui->setupUi(this);
}

CategoryMenu::~CategoryMenu()
{
    delete ui;
}
