#ifndef INSERTIONSORTER_H
#define INSERTIONSORTER_H

#include "abstractsorter.h"

class InsertionSorter : public AbstractSorter
{
public:
    InsertionSorter(std::vector<uint16_t> &values, QTimer *timer, int16_t &compared1, int16_t &compared2);
    virtual void sortStep();
    virtual void reset();
private:
    int i;
    int j;
    int key;
};

#endif // INSERTIONSORTER_H
