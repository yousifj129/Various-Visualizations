#ifndef INSERTIONSORTER_H
#define INSERTIONSORTER_H

#include "abstractsorter.h"

class InsertionSorter : public AbstractSorter
{
public:
    InsertionSorter();
    virtual void sortStep(std::vector<uint16_t> &values);
    virtual void reset();
};

#endif // INSERTIONSORTER_H
