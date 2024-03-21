#include "quicksorter.h"

QuickSorter::QuickSorter(std::vector<uint16_t> &values, QTimer *timer, int16_t &compared1, int16_t &compared2)
: AbstractSorter(values,timer,compared1,compared2)
{

}

void sortStep();
void reset();
