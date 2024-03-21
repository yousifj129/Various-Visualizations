#include "quicksorter.h"

QuickSorter::QuickSorter(std::vector<uint16_t> &values, QTimer *timer, int16_t &compared1, int16_t &compared2)
: AbstractSorter(values,timer,compared1,compared2)
{

}

void QuickSorter::sortStep(){
    if(b2){
        start2 = 0;
        end = this->values->size()-1;
        stack.push(start2);
        stack.push(end);
    }
    if(!stack.empty() || b3)
    {
        b2=false;
        if(b1){
        end = stack.top();
        stack.pop();
        start2 = stack.top();
        stack.pop();
        }
        partitionStep();
        if(b1){
        if(pivotIndex -1 > start2)
        {
            stack.push(start2);
            stack.push(pivotIndex-1);
            b3=false;
        }

        if(pivotIndex+1<end)
        {
            stack.push(pivotIndex+1);
            stack.push(end);
            b3=false;
        }
        }
    }
    else{
        return;
        timer->stop();
    }
}
void QuickSorter::reset(){
    b1=true;
    b2=true;
    b3=true;
    index=0;
    pivot=0;
    pivotIndex=0;
    start=0;
    start2=0;
    i=0;
    j=0;
    stack.empty();
}

void QuickSorter::partitionStep()
{
    if(b1){
    pivot = values->at(end);
    index = start2 - 1;
    j=start2;
    }
    if(j < end) {
    b1=false;
    b3=true;
        if (values->at(j) <= pivot) {
            std::swap(values->at(++index), values->at(j));
        *compared1=j;
        *compared2=index;
        }
        j++;
    }
    else{
        b1=true;
        std::swap(values->at(index + 1), values->at(end));
        *compared1=index+1;
        *compared2=end;
        pivotIndex=index+1;
        b3=false;
    }

}
