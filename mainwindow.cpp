#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto *pages = ui->stackedWidget;
    pages->setCurrentIndex(0);
    auto *actionExit = ui->actionExit;
    auto *actionSettings = ui->actionSettings;
    auto *actionAboutProject = ui->actionAbout_this_project;
    auto *actionAboutQt = ui->actionAbout_Qt;

    auto *startButton = ui->startButton;
    auto *aboutButton = ui->aboutButton;
    auto *exitButton = ui->exitButton;

    auto *startVisualizationButton = ui->startVisualizationButton;
    auto *stopVisualizationButton = ui->stopVisualizationButton;
    auto *toMenuButton = ui->toMenuButton;
    auto *idk = new QVBoxLayout(ui->customWidget);
    connect(actionExit,&QAction::triggered,[this]{this->close();});
    connect(exitButton, &QPushButton::clicked, [this]{this->close();});
    connect(startButton,&QPushButton::clicked, [pages]{pages->setCurrentIndex(1);});

    connect(startButton, &QPushButton::clicked, [this,idk]
            {
            this->sorter = new SortVisualizer();
        idk->addWidget(this->sorter);
            });

    connect(startVisualizationButton, &QPushButton::clicked, [this]{this->sorter->startVisualization();});
    connect(stopVisualizationButton, &QPushButton::clicked, [this]{this->sorter->stopVisualization();});
    connect(toMenuButton,&QPushButton::clicked, [pages]{pages->setCurrentIndex(0);});
    connect(toMenuButton,&QPushButton::clicked, [this]{delete this->sorter;});
    /*connect(ui->addRectButton, &QPushButton::clicked, [test]{
        test->a=3;
    });*/

    ui->sortMethodCombo->setStyleSheet("background-color:#535c68;");
    connect(ui->sortMethodCombo, &QComboBox::activated, [this]{this->sorter->changeSortMethod(ui->sortMethodCombo->currentIndex());});
}


MainWindow::~MainWindow()
{
    delete ui;
}

