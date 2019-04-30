#include "sortrecords.h"

sortRecords::sortRecords(QObject *parent)
{
    backuped = false;
    setParent(parent);
}
QStandardItemModel* sortRecords::Restore()const{
    return savedData;
}
void sortRecords::Backup(const QStandardItemModel *mod){
    savedData = new QStandardItemModel;
    headers(mod);
    boddy(mod);
    backuped = true;
}
bool sortRecords::hasBackup(){
    return backuped;
}
void sortRecords::headers(const QStandardItemModel *mod){
    col = mod->columnCount();
    for (int i=0; i < col; i++){
        h = mod->horizontalHeaderItem(i);
        h2 = new QStandardItem(h->text());
        savedData->setHorizontalHeaderItem(i, h2);
    }
}
void sortRecords::boddy(const QStandardItemModel *mod){
    row = mod->rowCount();
    col = mod->columnCount();
    for (int i=0; i < row; i++){
        for (int j = 0; j < col; j++){
            h2 = mod->item(i, j);
            h = new QStandardItem(h2->text());
            savedData->setItem(i, j, h);
        }
    }
}
sortRecords::~sortRecords(){
    savedData->clear();
    delete savedData;
    delete h;
    delete h2;
}
