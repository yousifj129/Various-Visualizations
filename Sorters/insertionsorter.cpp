#include "insertionsorter.h"

InsertionSorter::InsertionSorter(std::vector<uint16_t> &values, QTimer *timer, int16_t &compared1, int16_t &compared2)
: AbstractSorter(values,timer,compared1,compared2)
{
    i=1;
    j=0;
    key=this->values->at(i);
}

void InsertionSorter::sortStep()
{
    auto n = values->size();

    qDebug()<<i;
    if(i==n){
        return;
        timer->stop();
    }
    if(j>=0 && values->at(j)>key)
    {
        std::swap(values->at(j),values->at(j+1));
        j--;
        *compared1=j+1;
        *compared2=j;
    }
    else{
        *compared1=j+1;
        *compared2=j;
        i++;
        j=i-1;
        if(i==n){
            return;
            timer->stop();
        }
        key=values->at(i);
    }
}

void InsertionSorter::reset()
{
    i=1;
    j=0;
    key=values->at(i);
}
