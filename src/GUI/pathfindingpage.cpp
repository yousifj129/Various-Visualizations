#include "pathfindingpage.h"
#include "ui_pathfindingpage.h"

PathfindingPage::PathfindingPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PathfindingPage)
{
    ui->setupUi(this);
}

PathfindingPage::~PathfindingPage()
{
    delete ui;
}
