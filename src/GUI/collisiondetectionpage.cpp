#include "collisiondetectionpage.h"
#include "ui_collisiondetectionpage.h"

CollisionDetectionPage::CollisionDetectionPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CollisionDetectionPage)
{
    ui->setupUi(this);
}

CollisionDetectionPage::~CollisionDetectionPage()
{
    delete ui;
}
