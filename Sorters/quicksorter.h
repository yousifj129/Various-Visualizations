#ifndef QUICKSORTER_H
#define QUICKSORTER_H

#include "abstractsorter.h"

class QuickSorter : public AbstractSorter
{
public:
    QuickSorter(std::vector<uint16_t> &values, QTimer *timer, int16_t &compared1, int16_t &compared2);

    void sortStep();
    void reset();

private:
};

#endif // QUICKSORTER_H
