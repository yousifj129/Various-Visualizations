#include "sortvisualizer.h"

#include "utils.h"
#include "Sorters/sorters.h"

SortVisualizer::SortVisualizer(QWidget *parent)
    : QWidget(parent)
{
    qDebug()<<"Hello!";
    timer = new QTimer(this);
    sorter = new BubbleSorter(values,timer,compared1,compared2);
    connect(timer, &QTimer::timeout, this, &SortVisualizer::sortStep);
    changeSize(100);
    values[99]=1;
    //values={90,80,80,60,30,1,100,3,2,1};

}

SortVisualizer::~SortVisualizer()
{
    qDebug()<<"Goodbye!";
    delete sorter;
}

void SortVisualizer::sortStep()
{
    sorter->sortStep();
    update();
}

void SortVisualizer::changeSortMethod(int method)
{
    switch(method)
    {
    case 0:
        qDebug()<<"hii";
        delete sorter;
        qDebug()<<"wut1";
        sorter = new BubbleSorter(values,timer,compared1,compared2);
        qDebug()<<"wut2";
    break;
    case 1:
    delete sorter;
    sorter = new InsertionSorter(values,timer,compared1,compared2);
    break;
    case 2:
    delete sorter;
    sorter = new SelectionSorter(values,timer,compared1,compared2);
    break;
    case 3:

    delete sorter;
    sorter = new MergeSorter(values,timer,compared1,compared2);

    break;
    default:
    delete sorter;
    sorter = new BubbleSorter(values,timer,compared1,compared2);
    break;
    }
    timer->stop();
}
void SortVisualizer::startVisualization()
{
    sorter->reset();
    timer->start(10);
}

void SortVisualizer::stopVisualization()
{
    timer->stop();
}


void SortVisualizer::randomizeValues()
{
    maxValue=0;
    for(auto &v : values){
        v=Utils::randomInt(1,100);
        if(v>maxValue) maxValue=v;
    }
    resizeColumns();
}
void SortVisualizer::changeSize(uint16_t s)
{
    if(s>width()) s=width();
    values.resize(s);
    randomizeValues();
    resizeColumns();
}

void SortVisualizer::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, false);

    painter.setBrush(Qt::white);
    painter.setPen(Qt::PenStyle::NoPen);
    for(int i=0; i<values.size(); i++) painter.drawRect(colWidth*i, height()-values[i]*colHeight, colWidth, values[i]*colHeight);

    if(timer->isActive()){
    painter.setBrush(Qt::green);
    painter.drawRect(colWidth*compared1, height()-values[compared1]*colHeight,colWidth,values[compared1]*colHeight);
    painter.drawRect(colWidth*compared2, height()-values[compared2]*colHeight,colWidth,values[compared2]*colHeight);
    }
}

void SortVisualizer::resizeEvent(QResizeEvent *event){
    resizeColumns();
}

void SortVisualizer::resizeColumns()
{
    if(values.size()>width()){
    int x =width();
        changeSize(x);
    }
    colWidth=width()/values.size();
    colHeight=height()/maxValue;
}

void SortVisualizer::reset()
{
    randomizeValues();
    sorter->reset();
    timer->stop();
    update();
}
