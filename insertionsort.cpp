#include "insertionsort.h"

insertionSort::insertionSort(const QString & fn, QObject *parent)
{
    temp = fn;
    setParent(parent);
}
void insertionSort::run(){
    loadFile(temp);
    if (list->size() > 1){
        time.start();
        insertSort();
        Temp = fullFileName.back().split(".");
        fullFileName.pop_back();
        temp = QString("%1 insertionSort %2 %3.%4").arg(Temp.front()).arg(QDate::currentDate().toString("yyyyMMdd")).arg(QTime::currentTime().toString("mm_ss")).arg(Temp.back());
        fullFileName.append(temp);
        temp = QString("%1").arg(time.elapsed());
        emit(newFileName(fullFileName.back(),temp));
        writeFile();
    }else
        emit errorMsg("This file can not be sorted.");
}
void insertionSort::insertSort()
{
    int firstOutOfOrder, location;
    for (firstOutOfOrder = 1; firstOutOfOrder < list->size(); firstOutOfOrder++){
        a = list->at(firstOutOfOrder);
        b = list->at(firstOutOfOrder - 1);
        if (a < b){
            temp = a;
            location = firstOutOfOrder;
            do{
                b = list->at(location - 1);
                list->replace(location, b);
                location--;
            }while ((location > 0) && (b > temp));
            list->replace(location, temp);
        }
    }
}
