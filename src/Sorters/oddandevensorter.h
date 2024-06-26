#ifndef ODDANDEVENSORTER_H
#define ODDANDEVENSORTER_H

#include "abstractsorter.h"
#include <stack>

class OddAndEvenSorter : public AbstractSorter
{
public:
    OddAndEvenSorter(std::vector<uint16_t> &values, QTimer *timer, int16_t &compared1, int16_t &compared2);

    void sortStep();
    void reset();

private:
    void oddAndEvenSortStep();
    int i;
    int j;
    bool b1 = true;
    bool b2 = true;
    bool b3 = true;
    int index;
    int pivot;
    int pivotIndex;
    int start;
    int start2;
    int end;
};

#endif // ODDANDEVENSORTER_H