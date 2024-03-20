#include "mergesorter.h"


MergeSorter::MergeSorter(std::vector<uint16_t> &values, QTimer *timer, int16_t &compared1, int16_t &compared2)
: AbstractSorter(values,timer,compared1,compared2)
{
    i=1;
    j=0;
    k=0;
    p=0;
    somebool=true;
}

void MergeSorter::sortStep()
{
    int n = values->size();
    if(i<=n-1){
        if(j<n-1){
            int mid = std::min(j + i - 1, n - 1);
            int right_end = std::min(j + 2 * i - 1, n - 1);
            mergeStep(j,mid,right_end);
        }
        else{
            j=0;
            i*=2;
        }
    }
    else timer->stop();
}

void MergeSorter::mergeStep(int left_start, int mid, int right_end)
{
    qDebug()<<"Merge step!";
    size = right_end-left_start+1;
    left_end=mid;
    right_start=mid+1;
    if(somebool){
        temp.resize(size);
        p=0;
        r = right_start;
        l = left_start;
    }

    if(l <= left_end && r <= right_end){
        if(values->at(l)<values->at(r)){
            *compared1=j+p;
            *compared2=l;
            temp[p++] = values->at(l++);
        }
        else{
            *compared1=j+p;
            *compared2=r;
            temp[p++] = values->at(r++);

        }
        somebool=false;
    }
    else{
        while(l<=left_end) temp[p++] = values->at(l++);
        while(r<=right_end) temp[p++] = values->at(r++);

        if(k < size) {
            values->at(left_start + k) = temp[k];
            k++;

        }
        else{
            j+=i*2;
            somebool=true;
            k=0;
        }
    }

    qDebug()<<"i: "<<i<<"j: "<<j<<"k: "<<k<<"p: "<<p;
}
void MergeSorter::reset()
{
    i=1;
    j=0;
    k=0;
    p=0;
    somebool=true;
}
