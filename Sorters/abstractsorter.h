#ifndef ABSTRACTSORTER_H
#define ABSTRACTSORTER_H


#include <cstdint>
#include <vector>

class AbstractSorter
{
public:
    AbstractSorter();
    virtual void sortStep(std::vector<uint16_t> &values);
    virtual void reset();
    int a=3;
};

#endif // ABSTRACTSORTER_H
