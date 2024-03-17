#include "sortvisualizer.h"

#include "utils.h"

SortVisualizer::SortVisualizer(QWidget *parent)
    : QWidget(parent)
{
    qDebug()<<"Hello!";
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SortVisualizer::sortStep);

    changeSize(20);
}

SortVisualizer::~SortVisualizer()
{
    qDebug()<<"Goodbye!";
}
void SortVisualizer::startVisualization()
{
    qDebug()<<"Starting!";
    timer->start(20);
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

void SortVisualizer::sortStep()
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
    if((compared1 != -1 || compared2 != -1) && timer->isActive()){
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

