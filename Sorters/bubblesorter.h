#ifndef BUBBLESORTER_H
#define BUBBLESORTER_H

#include "abstractsorter.h"

class BubbleSorter : public AbstractSorter
{
public:
    BubbleSorter();
    virtual void sortStep(std::vector<uint16_t> &values);
    virtual void reset();
};

#endif // BUBBLESORTER_H
