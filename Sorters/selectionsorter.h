#ifndef SELECTIONSORTER_H
#define SELECTIONSORTER_H

#include "abstractsorter.h"

class SelectionSorter : public AbstractSorter
{
public:

    SelectionSorter();
    virtual void sortStep(std::vector<uint16_t> &values);
    virtual void reset();
};

#endif
