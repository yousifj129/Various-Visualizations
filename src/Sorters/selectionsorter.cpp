#include "selectionsorter.h"
#include "qdebug.h"

SelectionSorter::SelectionSorter(std::vector<uint16_t> &values, QTimer *timer, int16_t &compared1, int16_t &compared2)
: AbstractSorter(values,timer,compared1,compared2)
{
    i=0;
    j=0;
    key=0;
}

void SelectionSorter::sortStep()
{
    auto n=values->size();
    if(i<n){
        if(j<n){
            if(values->at(j)<values->at(key)) key=j;
            *compared1=j;
            *compared2=key;
            j++;
        }
        else{
            std::swap(values->at(key),values->at(i));
            i++;
            j=i+1;
            key=i;
        }
    }
}

void SelectionSorter::reset()
{
    i=0;
    j=0;
    key=0;
}
