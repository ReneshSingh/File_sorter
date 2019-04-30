#ifndef FILEIO_H
#define FILEIO_H

#include <QObject>
#include <QFile>
#include <QStringList>
#include <QTextStream>

class FileIO : public QObject
{
    Q_OBJECT
public:
    explicit FileIO(QObject *parent = 0);
    ~FileIO();
    virtual QStringList* loadFile(const QString fn);
    virtual void writeFile(const QString fn, const QStringList *list);
private:
    QFile *file;
    QStringList *data;
    QTextStream t;
    QString s;
};

#endif // FILEIO_H
