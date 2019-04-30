#include "threadmanager.h"
#include "selectionsort.h"

ThreadManager::ThreadManager(QObject *parent){
    threadPool = new QThreadPool(this);
    numThreads = new QList<AbstractSort*>;
    threadPool->setMaxThreadCount(3);
    setParent(parent);
}
bool ThreadManager::processFile(const QString & fn, const int & sortAlgorithm){
    if ((threadPool->activeThreadCount() < 3) && (numThreads->size() < 3)){
        if(sortAlgorithm==0){
            insertionSort *iSort = new insertionSort(fn, this);
            connect(iSort, SIGNAL(finished()), this, SLOT(threadFinished()));
            connect(iSort, SIGNAL(newFileName(QString,QString)), this, SLOT(newFileName(QString,QString)));
            connect(iSort, SIGNAL(errorMsg(QString)), this, SLOT(reportedError(QString)));
            connect(this, SIGNAL(endThreads()), iSort, SLOT(quit()));
            numThreads->append(iSort);
            iSort->start(QThread::HighestPriority);
        }else{
            selectionSort *sSort = new selectionSort(fn, this);
            connect(sSort, SIGNAL(finished()), this, SLOT(threadFinished()));
            connect(sSort, SIGNAL(newFileName(QString,QString)), this, SLOT(newFileName(QString,QString)));
            connect(sSort, SIGNAL(errorMsg(QString)), this, SLOT(reportedError(QString)));
            connect(this, SIGNAL(endThreads()), sSort, SLOT(quit()));
            numThreads->append(sSort);
            sSort->start(QThread::HighestPriority);
        }
        return true;
    }else
        return false;
}
void ThreadManager::threadFinished(){
    //QObject *o;
    for(int i = 0; i < numThreads->size(); i++)
        if (numThreads->at(i)->isFinished())
            numThreads->removeAt(i);
            //o = numThreads->takeAt(i);
    //o->deleteLater();
}
void ThreadManager::newFileName(const QString fn, const QString te){
    emit fileSorted(fn, te);
}
void ThreadManager::canselThreads(){
    emit endThreads();
}
int ThreadManager::activeThreads()const{
    return numThreads->size();
}
void ThreadManager::reportedError(QString msg){
    emit errorMsg(msg);
}
ThreadManager::~ThreadManager(){
    numThreads->clear();
    delete numThreads;
    delete threadPool;
    delete tmm;
}
ThreadManager* ThreadManager::tmm=0;
ThreadManager* ThreadManager::instance(QObject *parent){
    if (tmm == 0)
        tmm = new ThreadManager(parent);
    return tmm;
}
