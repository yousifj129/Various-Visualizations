#include "sortpage.h"
#include "ui_sortpage.h"
#include <QDebug>
SortPage::SortPage(QStackedWidget *pages, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SortPage)
{
    ui->setupUi(this);
    qDebug()<<"hi";

    auto *resetButton = ui->resetButton;
    auto *startVisualizationButton = ui->startVisualizationButton;
    auto *stopVisualizationButton = ui->stopVisualizationButton;
    auto *toMenuButton = ui->toMenuButton;
    auto *idk = new QVBoxLayout(ui->customWidget);
    sorter = new SortVisualizer();
    idk->addWidget(this->sorter);


    connect(startVisualizationButton, &QPushButton::clicked, [this]{this->sorter->startVisualization();});
    connect(stopVisualizationButton, &QPushButton::clicked, [this]{this->sorter->stopVisualization();});
    connect(toMenuButton,&QPushButton::clicked, [this,pages]{
        pages->removeWidget(this);
        delete this->sorter;
        delete this;
        pages->setCurrentIndex(1);
    });

    ui->sortMethodCombo->setStyleSheet("background-color:#535c68;");
    connect(ui->sortMethodCombo, &QComboBox::activated, [this]{this->sorter->changeSortMethod(ui->sortMethodCombo->currentIndex());});
    connect(resetButton,&QPushButton::clicked,[this]{this->sorter->reset();});
}

SortPage::~SortPage()
{
    delete ui;
}
