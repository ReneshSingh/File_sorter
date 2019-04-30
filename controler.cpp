#include "controler.h"

controler::controler(QObject *parent) :
    QObject(parent)
{
    QStringList tempList;
    model = new  QStandardItemModel;
    siml = new QList<QStandardItemModel*>;
    tempList << "File" << "Time taken (milliseconds)";
    model->setHorizontalHeaderLabels(tempList);
}
QStandardItemModel* controler::dataSet()const{
    return model;
}
void controler::record(const QString fn, const QString te){
    QList<QStandardItem*> tsl;
    QStandardItem *s1 = new QStandardItem(fn);
    QStandardItem *s2 = new QStandardItem(te);
    tsl << s1 << s2;
    model->appendRow(tsl);
}
void controler::backupModel(){
    savedModel.Backup(model);
}
QStandardItemModel* controler::RestoredModel(){
    if (savedModel.hasBackup()){
        siml->append(model);
        model = savedModel.Restore();
    }
    return model;
}
controler::~controler(){
    model->clear();
    siml->clear();
    delete siml;
    delete model;
}
