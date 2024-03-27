#include "bubblesorter.h"

BubbleSorter::BubbleSorter(std::vector<uint16_t> &values, QTimer *timer, int16_t &compared1, int16_t &compared2)
    : AbstractSorter(values,timer,compared1,compared2)
{
    i=0;
    j=0;
}

void BubbleSorter::sortStep()
{
    auto n = values->size();

    if(j==n-1) timer->stop();
    if(i<n-j-1){
        *compared1=i;
        *compared2=i+1;
        if (values->at(i) > values->at(i + 1)) {
            std::swap(values->at(i), values->at(i + 1));
        }
        i++;
    }
    else{
        i=0;
        j++;
    }
}

void BubbleSorter::reset()
{
    i=0;
    j=0;
}
