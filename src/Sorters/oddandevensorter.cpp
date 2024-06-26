#include "oddandevensorter.h"

OddAndEvenSorter::OddAndEvenSorter(std::vector<uint16_t> &values, QTimer *timer, int16_t &compared1, int16_t &compared2)
    : AbstractSorter(values, timer, compared1, compared2)
{

}

void OddAndEvenSorter::sortStep()
{
    if (b2)
    {
        start2 = 0;
        end = this->values->size() - 1;
    }
    if (start2 % 2 == 0)
    {
        oddAndEvenSortStep();
    }
    else
    {
        oddAndEvenSortStep();
    }
    if (start2 >= end && b2)
    {
        return;
        timer->stop();
    }
}

void OddAndEvenSorter::reset()
{
    b1 = true;
    b2 = true;
    b3 = true;
    index = 0;
    pivot = 0;
    pivotIndex = 0;
    start = 0;
    start2 = 0;
    i = 0;
    j = 0;
    while (!stack.empty()) stack.pop();
}

void OddAndEvenSorter::oddAndEvenSortStep()
{
    if (b1)
    {
        i = start2;
        b1 = false;
        b3 = true;
    }
    if (i < end)
    {
        if (values->at(i) > values->at(i + 1))
        {
            std::swap(values->at(i), values->at(i + 1));
            *compared1 = i;
            *compared2 = i + 1;
        }
        i += 2;
    }
    else
    {
        b1 = true;
        start2++;
        b2 = !b2;
    }
}