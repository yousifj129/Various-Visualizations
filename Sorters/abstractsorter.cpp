#include "abstractsorter.h"
#include <iostream>
AbstractSorter::AbstractSorter(std::vector<uint16_t> &values, QTimer *timer, int16_t &compared1, int16_t &compared2)
    : values(&values), compared1(&compared1), compared2(&compared2)
{
    this->timer=timer;

}

AbstractSorter::AbstractSorter()
: values(nullptr), compared1(nullptr), compared2(nullptr)
{

}

void AbstractSorter::sortStep()
{
 qDebug()<<"hi abstract";
}

void AbstractSorter::reset()
{

}
