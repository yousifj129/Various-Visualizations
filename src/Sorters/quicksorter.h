#ifndef QUICKSORTER_H
#define QUICKSORTER_H

#include "abstractsorter.h"
#include <stack>

class QuickSorter : public AbstractSorter
{
public:
    QuickSorter(std::vector<uint16_t> &values, QTimer *timer, int16_t &compared1, int16_t &compared2);

    void sortStep();
    void reset();

private:
    void partitionStep();
    int i;
    int j;
    bool b1=true;
    bool b2=true;
    bool b3=true;
    int index;
    int pivot;
    int pivotIndex;
    std::stack<int> stack;
    int start;
    int start2;
    int end;
};

#endif // QUICKSORTER_H
