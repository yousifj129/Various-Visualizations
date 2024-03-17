#include "sortvisualizer.h"

#include "utils.h"

SortVisualizer::SortVisualizer(QWidget *parent)
    : QWidget(parent)
{
    qDebug()<<"Hello!";
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SortVisualizer::bubbleSortStep);

    changeSize(100);
    //values={90,80,80,60,30,1,100,3,2,1};
}

SortVisualizer::~SortVisualizer()
{
    qDebug()<<"Goodbye!";
}

void SortVisualizer::changeSortMethod(int method)
{
    disconnect(timer, &QTimer::timeout,0,0);
    switch(method)
    {
    case 0:
    connect(timer, &QTimer::timeout, this, &SortVisualizer::bubbleSortStep);
    starti=0;
    startj=0;

    break;
    case 1:
    connect(timer, &QTimer::timeout, this, &SortVisualizer::insertionSortStep);
    starti=1;
    startj=0;

    break;
    default:
    connect(timer, &QTimer::timeout, this, &SortVisualizer::bubbleSortStep);
    starti=0;
    startj=0;

    break;
    }
}
void SortVisualizer::startVisualization()
{
    i=starti;
    j=startj;
    key=values[starti];
    timer->start(2);
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

void SortVisualizer::bubbleSortStep()
{
    auto n = values.size();
    if(j==n-1) timer->stop();
    if(i<n-j-1){
        compared1=i;
        compared2=i+1;
        if (values[i] > values[i + 1]) {
            std::swap(values[i], values[i + 1]);
            qDebug()<<"SWAP!";
        }
            i++;
    }
    else{
            i=0;
            j++;
    }
    qDebug()<<"sorting!";
    update();
}

void SortVisualizer::insertionSortStep()
{
    qDebug()<<"sortstart";
    auto n = values.size();

    if(i==n) timer->stop();

    if(j>=0 && values[j]>key)
    {
            std::swap(values[j],values[j+1]);
            j--;
            compared1=j+1;
            compared2=j;
    }
    else{
            compared1=j+1;
            compared2=j;
            i++;
            j=i-1;
            key=values[i];
    }
    update();
}
void SortVisualizer::paintEvent(QPaintEvent *event)
{
    qDebug()<<"drawing!";
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, false);

    painter.setBrush(Qt::white);
    painter.setPen(Qt::PenStyle::NoPen);
    for(int i=0; i<values.size(); i++) painter.drawRect(colWidth*i, height()-values[i]*colHeight, colWidth, values[i]*colHeight);

    qDebug()<<"Compared1: "<<compared1<<"Compared2: "<<compared2;
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

