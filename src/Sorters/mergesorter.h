#ifndef MERGESORTER_H
#define MERGESORTER_H

#include "abstractsorter.h"

class MergeSorter : public AbstractSorter
{
public:

    MergeSorter(std::vector<uint16_t> &values, QTimer *timer, int16_t &compared1, int16_t &compared2);
    virtual void sortStep();
    virtual void reset();
private:
    void mergeStep(int left_start, int mid, int right_end);

    int i;
    int j;
    int l;
    int r;
    int p = 0;
    int k = 0;

    int size;
    int mergeSize;
    int left_end;
    int right_start;
    bool somebool;
    std::vector<int> temp;
};

#endif
