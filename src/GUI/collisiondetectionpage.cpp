#include "collisiondetectionpage.h"
#include "ui_collisiondetectionpage.h"

CollisionDetectionPage::CollisionDetectionPage(QStackedWidget *pages, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CollisionDetectionPage)
{
    ui->setupUi(this);

    auto *toMenuButton = ui->toMenuButton;

    connect(toMenuButton, &QPushButton::clicked, [this,pages]{

        pages->removeWidget(this);
        delete this;
        pages->setCurrentIndex(1);

    });
}

CollisionDetectionPage::~CollisionDetectionPage()
{
    delete ui;
}
