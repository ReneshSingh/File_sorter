#include "fileio.h"

FileIO::FileIO(QObject *parent) :
    QObject(parent)
{
    file = new QFile(this);
    data = new QStringList;
    t.setDevice(file);
}
QStringList* FileIO::loadFile(const QString fn){
    data->clear();
    file->setFileName(fn);
    file->open(QIODevice::ReadOnly);
    while(!t.atEnd()){
        t >> s;
        data->append(s);
    }
    file->close();
    return data;
}
void FileIO::writeFile(const QString fn, const QStringList *list){
    file->setFileName(fn);
    file->open(QIODevice::WriteOnly);
    for(int i=0; i < list->size(); i++){
        t << list->at(i) << "; \n";
        t.flush();
    }
    file->close();
}
FileIO::~FileIO(){
    data->clear();
    delete file;
    delete data;
}
