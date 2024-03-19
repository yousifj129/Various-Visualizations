#ifndef MERGESORTER_H
#define MERGESORTER_H

#include "abstractsorter.h"

class MergeSorter : public AbstractSorter
{
public:

    MergeSorter();
    virtual void sortStep(std::vector<uint16_t> &values);
    virtual void reset();
};

#endif
