#include "sortvisualizer.h"

#include "../Utilities/utils.h"
#include "../Sorters/sorters.h"


SortVisualizer::SortVisualizer(QWidget *parent)
    : QWidget(parent)
{
    timer = new QTimer(this);
    sorter = new BubbleSorter(values,timer,compared1,compared2);
    connect(timer, &QTimer::timeout, this, &SortVisualizer::sortStep);
    changeSize(100);

}

SortVisualizer::~SortVisualizer()
{
    delete sorter;
}

void SortVisualizer::sortStep()
{
    sorter->sortStep();
    update();
}

void SortVisualizer::changeSortMethod(Sorter method)
{
    switch(method)
    {
    case Sorter::Bubble:
        delete sorter;
        sorter = new BubbleSorter(values,timer,compared1,compared2);
    break;
    case Sorter::Insertion:
    delete sorter;
    sorter = new InsertionSorter(values,timer,compared1,compared2);
    break;
    case Sorter::Selection:
    delete sorter;
    sorter = new SelectionSorter(values,timer,compared1,compared2);
    break;
    case Sorter::Merge:

    delete sorter;
    sorter = new MergeSorter(values,timer,compared1,compared2);

    break;
    case Sorter::Quick:
    delete sorter;
    sorter = new QuickSorter(values,timer,compared1,compared2);
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
    sorter->reset();
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
