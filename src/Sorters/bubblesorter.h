#ifndef BUBBLESORTER_H
#define BUBBLESORTER_H

#include "abstractsorter.h"

class BubbleSorter : public AbstractSorter
{
public:
    BubbleSorter(std::vector<uint16_t> &values, QTimer *timer, int16_t &compared1, int16_t &compared2);
    virtual void sortStep();
    virtual void reset();
private:
    int i;
    int j;
};

#endif // BUBBLESORTER_H
