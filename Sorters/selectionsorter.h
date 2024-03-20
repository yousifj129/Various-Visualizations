#ifndef SELECTIONSORTER_H
#define SELECTIONSORTER_H

#include "abstractsorter.h"

class SelectionSorter : public AbstractSorter
{
public:

    SelectionSorter(std::vector<uint16_t> &values, QTimer *timer, int16_t &compared1, int16_t &compared2);
    virtual void sortStep();
    virtual void reset();
private:
    int i;
    int j;
    int key;
};

#endif
