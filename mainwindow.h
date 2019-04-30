#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "threadmanager.h"
#include <QDialog>
#include <QVBoxLayout>
#include "ui_mainwindow.h"
#include "controler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void errorMsg(QString error);
private slots:
    void errorDis(QString msg);
    void selectFile();
    void sortFile();
    void enableUI();
    void safeClose();
    void Backup();
    void Restore();
private:
    Ui::MainWindow *ui;
    QString f;
    ThreadManager *tm;
    QDialog *d;
    QVBoxLayout *v;
    QLabel *l;
    QPushButton *pb, *fq;
    controler *cont;
};

#endif // MAINWINDOW_H
