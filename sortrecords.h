#ifndef SORTRECORDS_H
#define SORTRECORDS_H

#include <QObject>
#include <QStandardItemModel>

class sortRecords : public QObject
{
    Q_OBJECT
public:
    explicit sortRecords(QObject *parent = 0);
    ~sortRecords();
    QStandardItemModel* Restore()const;
    virtual void Backup(const QStandardItemModel *mod);
    virtual bool hasBackup();
private:
    virtual void headers(const QStandardItemModel *mod);
    virtual void boddy(const QStandardItemModel *mod);
    int row, col;
    bool backuped;
    QStandardItemModel *savedData;
    QStandardItem *h,*h2;
};

#endif // SORTRECORDS_H
