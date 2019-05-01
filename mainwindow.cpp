#include "mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    tm = ThreadManager::instance(qApp);
    d = new QDialog(this);
    v = new QVBoxLayout(d);
    l = new QLabel(d);
    pb = new QPushButton("ok",d);
    cont = new controler(this);
    fq = new QPushButton("Force quit",d);
    ui->setupUi(this);
    ui->tableView->setModel(cont->dataSet());
    d->setWindowTitle("Error");
    v->addWidget(l);
    v->addWidget(pb);
    v->addWidget(fq);
    fq->setHidden(true);
    d->setLayout(v);
    connect(pb, SIGNAL(clicked()), d, SLOT(close()));
    connect(pb, SIGNAL(clicked()), this, SLOT(enableUI()));
    connect(fq, SIGNAL(clicked()),this, SLOT(safeClose()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(safeClose()));
    connect(ui->fileButton, SIGNAL(clicked()), this, SLOT(selectFile()));
    connect(ui->GoButton, SIGNAL(clicked()), this, SLOT(sortFile()));
    connect(this,SIGNAL(errorMsg(QString)), this, SLOT(errorDis(QString)));
    connect(tm,SIGNAL(errorMsg(QString)), this, SLOT(errorDis(QString)));
    connect(tm, SIGNAL(fileSorted(QString,QString)), cont, SLOT(record(QString,QString)));
    connect(ui->actionBackup, SIGNAL(triggered()), this, SLOT(Backup()));
    connect(ui->actionRestore, SIGNAL(triggered()), this, SLOT(Restore()));
    connect(d, SIGNAL(rejected()), this, SLOT(enableUI()));
    connect(qApp, SIGNAL(aboutToQuit()), this, SLOT(safeClose()));
}
void MainWindow::selectFile(){
    QFileDialog *fd = new QFileDialog(this);
    f = fd->getOpenFileName();
    ui->fileName->setText(QString("File name: %1").arg(f.split("/").back()));
    if (f.isEmpty())
        ui->GoButton->setEnabled(false);
    else
        ui->GoButton->setEnabled(true);
    fd->close();
    ui->sort->setFocus();
}
void MainWindow::sortFile(){
    if (!tm ->processFile(f,ui->sort->currentIndex()))
        emit(errorMsg("The sort process cannot \n be run at the current time."));
}
void MainWindow::errorDis(QString msg){
    qApp->beep();
    ui->centralWidget->setEnabled(false);
    l->setText(msg);
    d->show();
}
void MainWindow::enableUI(){
    ui->centralWidget->setEnabled(true);
    fq->setHidden(true);
    pb->setText("Ok");
}
void MainWindow::safeClose(){
    QVariant o = sender()->metaObject()->className();
    if (tm->activeThreads()==0)
        exit(EXIT_SUCCESS);
    else if((o.toString() == "QPushButton")|| (o.toString() == "QApplication")){
        tm->canselThreads();
        exit(EXIT_SUCCESS);
    }else{
        fq->setHidden(false);
        pb->setText("No");
        emit errorMsg("Still sorting files, would you still \n like to exit the application?");
    }
}
void MainWindow::Backup(){
    cont->backupModel();
    ui->actionRestore->setEnabled(true);
}
void MainWindow::Restore(){
    ui->tableView->setModel(cont->RestoredModel());
    cont->backupModel();
}
MainWindow::~MainWindow()
{
    tm->canselThreads();
    delete ui;
    delete tm;
    delete cont;
    delete d;
    delete v;
    delete l;
    delete pb;
    delete fq;
}
