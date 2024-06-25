#include "categorymenu.h"
#include "ui_categorymenu.h"


CategoryMenu::CategoryMenu(QStackedWidget *pages, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CategoryMenu)
{
    ui->setupUi(this);
    /*pages->addWidget(sortPage);
    pages->addWidget(collisionDetectionPage);
    pages->addWidget(pathFindingPage);*/
    auto *sortingButton = ui->sortingButton;
    auto *collisionButton = ui->collisionButton;
    auto *mainmenuButton = ui->MenuButton;
    connect(sortingButton, &QPushButton::clicked, [this, pages, parent]{
        this->sortPage = new SortPage(pages,parent);
        pages->addWidget(this->sortPage);
        pages->setCurrentIndex(2);

    });

    connect(collisionButton, &QPushButton::clicked, [this,pages,parent]{
        this->collisionDetectionPage = new CollisionDetectionPage(pages,parent);
        pages->addWidget(this->collisionDetectionPage);
        pages->setCurrentIndex(2);
    });

    connect(mainmenuButton, &QPushButton::clicked, [this,pages]{
        pages->removeWidget(this);
        pages->setCurrentIndex(0);
        delete this;
    });
}

CategoryMenu::~CategoryMenu()
{
    delete ui;
}
