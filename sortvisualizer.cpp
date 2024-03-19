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
    method=0;
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
    method=0;

    break;
    case 1:
    connect(timer, &QTimer::timeout, this, &SortVisualizer::insertionSortStep);
    starti=1;
    startj=0;
    method=1;
    key=values[starti];
    break;
    case 2:
    connect(timer, &QTimer::timeout,this, &SortVisualizer::selectionSortStep);
    starti=0;
    startj=0;
    method=2;
    key=0;
    break;
    case 3:
        qDebug()<<"what the f";
        connect(timer, &QTimer::timeout, this, &SortVisualizer::mergeSortStep);
        starti=1;
        startj=0;
        method=3;
    break;
    default:
    connect(timer, &QTimer::timeout, this, &SortVisualizer::bubbleSortStep);
    starti=0;
    startj=1;

    break;
    }
    timer->stop();
}
void SortVisualizer::startVisualization()
{
    i=starti;
    j=startj;
    if(method==1) key=values[starti];
    else if(method==2) key=starti;

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

void SortVisualizer::selectionSortStep()
{
    qDebug()<<"select!!";
    qDebug()<<key;
    auto n=values.size();
    if(i<n){
    if(j<n){
            qDebug()<<"hi";
            if(values[j]<values[key]) key=j;
            compared1=j;
            compared2=key;
            j++;
            qDebug()<<"hi2";
    }
    else{
            std::swap(values[key],values[i]);
            i++;
            j=i+1;
            key=i;
    }
    }
    qDebug()<<"IDK";
    update();
}

void SortVisualizer::mergeSortStep()
{
    int n = values.size();
    qDebug()<<"hi?";
    if(i<=n-1){
        if(j<n-1){
            int mid = std::min(j + i - 1, n - 1);
            int right_end = std::min(j + 2 * i - 1, n - 1);
            merge(values, j, mid, right_end);
            j+=2*i;
        }
        else{
        j=0;
        i*=2;
        }
    }
    else{
        timer->stop();
        qDebug()<<"ENDED";
    }
    update();
}

void SortVisualizer::merge(std::vector<uint16_t> &arr, int left_start, int mid, int right_end)
{
    int size = right_end-left_start+1;
    int left_end=mid;
    int right_start=mid+1;

    std::vector<int> temp(size);
    int i=0;
    int r = right_start;
    int l = left_start;
    while(l <= left_end && r <= right_end)
        arr[l]<arr[r] ?  temp[i++] = arr[l++] : temp[i++] = arr[r++];

    while(l<=left_end) temp[i++] = arr[l++];
    while(r<=right_end) temp[i++] = arr[r++];

    for (int k = 0; k < size; ++k) {
        arr[left_start + k] = temp[k];
    }
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

void SortVisualizer::reset()
{
    randomizeValues();
    i=starti;
    j=startj;
    key=values[starti];
    timer->stop();
    update();
}
