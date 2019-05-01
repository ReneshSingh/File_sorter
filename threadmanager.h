#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QObject>
#include <QThreadPool>
#include <QFutureWatcher>
#include <QList>
#include "abstractsort.h"
#include "insertionsort.h"

class ThreadManager : public QObject
{
    Q_OBJECT
public:
    ~ThreadManager();
    static ThreadManager* instance(QObject *parent);
    virtual bool processFile(const QString & fn, const int & sortAlgorithm);
    virtual void canselThreads();
    virtual int activeThreads()const;
signals:
    void fileSorted(const QString fn, const QString te);
    void endThreads();
    void errorMsg(QString msg);
protected:
    QThreadPool *threadPool;
private slots:
    void reportedError(QString msg);
    void threadFinished();
    void newFileName(const QString fn, const QString te);
private:
    explicit ThreadManager(QObject *parent);
    static ThreadManager *tmm;
    QList<AbstractSort*> *numThreads;
};

#endif // THREADMANAGER_H
