#ifndef ABSTRACTSORTER_H
#define ABSTRACTSORTER_H


#include <cstdint>
#include <vector>
#include <QTimer>
#include <QDebug>

class AbstractSorter
{
public:
    AbstractSorter(std::vector<uint16_t> &values, QTimer *timer, int16_t &compared1, int16_t &compared2);
    AbstractSorter();
    virtual void sortStep();
    virtual void reset();
protected:
    std::vector<uint16_t> *values;
    QTimer *timer;
    int16_t *compared1;
    int16_t *compared2;
};

#endif // ABSTRACTSORTER_H
