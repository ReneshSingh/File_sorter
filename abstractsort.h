#ifndef ABSTRACTSORT_H
#define ABSTRACTSORT_H

#include <QObject>
#include <QThread>
#include <QStringList>
#include "fileio.h"
#include <QTime>
#include <QDate>

class AbstractSort : public QThread
{
    Q_OBJECT
public:
    explicit AbstractSort(QObject *parent = 0);
    ~AbstractSort();
signals:
    void newFileName(const QString fn, const QString te);
    void errorMsg(QString msg);
protected:
    virtual void loadFile(const QString fn);
    virtual void writeFile();
    QStringList *list, fullFileName, Temp;
    QString temp, a, b;
    QTime time;
private:
    FileIO *file;
};

#endif // ABSTRACTSORT_H
