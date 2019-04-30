#include "abstractsort.h"

AbstractSort::AbstractSort(QObject *parent)
{
    list = new QStringList;
    file = new FileIO;
    setParent(parent);
}
void AbstractSort::loadFile(const QString fn){
    list = file->loadFile(fn);
    fullFileName = fn.split("/");
}
void AbstractSort::writeFile(){
    temp.clear();
    while(!fullFileName.isEmpty()){
        if (fullFileName.front() != fullFileName.back())
            temp += fullFileName.front() + "/";
        else
            temp += fullFileName.front();
        fullFileName.pop_front();
    }
    file->writeFile(temp, list);
}
AbstractSort::~AbstractSort(){
    list->clear();
    fullFileName.clear();
    delete list;
    delete file;
}
