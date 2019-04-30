#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <QObject>
#include "abstractsort.h"

class insertionSort : public AbstractSort
{
    Q_OBJECT
public:
    explicit insertionSort(const QString & fn, QObject *parent = 0);
    virtual void run();
private:
    virtual void insertSort();
};

#endif // INSERTIONSORT_H
