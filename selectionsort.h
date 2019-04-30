#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <QObject>
#include "abstractsort.h"

class selectionSort : public AbstractSort
{
    Q_OBJECT
public:
    explicit selectionSort(const QString & fn, QObject *parent = 0);
    virtual void run();
private:
    virtual void swap(const int first, const int second);
    virtual int minLocation(const int first, const int last);
    virtual void selectSort();
    int minIndex;
};

#endif // SELECTIONSORT_H
