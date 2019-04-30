#include "selectionsort.h"

selectionSort::selectionSort(const QString & fn, QObject *parent)
{
    temp = fn;
    setParent(parent);
}
void selectionSort::run(){
    loadFile(temp);
    if (list->size() > 1){
        time.start();
        selectSort();
        Temp = fullFileName.back().split(".");
        fullFileName.pop_back();
        temp = QString("%1 selectionSort %2 %3.%4").arg(Temp.front()).arg(QDate::currentDate().toString("yyyyMMdd")).arg(QTime::currentTime().toString("mm_ss")).arg(Temp.back());
        fullFileName.append(temp);
        temp = QString("%1").arg(time.elapsed());
        emit(newFileName(fullFileName.back(),temp));
        writeFile();
    }else
        emit errorMsg("This file can not be sorted.");
}
void selectionSort::selectSort()
{
    int x = list->size() - 1;
    for (int loc = 0; loc < x; loc++){
        minIndex = minLocation(loc, list->size() - 1);
        list->swap(loc, minIndex);
        //swap(loc, minIndex);
    }
}
int selectionSort::minLocation(const int first, const int last)
{
    minIndex = first;
    b = list->at(minIndex);
    for (int loc = first + 1; loc <= last; loc++){
        a = list->at(loc);
        if (a < b){
            minIndex = loc;
            b = list->at(minIndex);
        }
    }
    return minIndex;
}
void selectionSort::swap(const int first, const int second)
{
    temp = list->at(first);
    a = list->at(second);
    list->replace(second, temp);
    list->replace(first, a);
}
