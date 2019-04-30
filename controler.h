#ifndef CONTROLER_H
#define CONTROLER_H

#include <QObject>
#include <QStandardItemModel>
#include "sortrecords.h"

class controler : public QObject
{
    Q_OBJECT
public:
    explicit controler(QObject *parent = 0);
    ~controler();
    virtual QStandardItemModel* dataSet()const;
    virtual void backupModel();
    QStandardItemModel* RestoredModel();
public slots:
    void record(const QString fn, const QString te);
private:
    QList<QStandardItemModel*> *siml;
    sortRecords savedModel;
    QStandardItemModel *model;
};

#endif // CONTROLER_H
