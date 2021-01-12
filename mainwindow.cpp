#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScreen>
#include <QMenu>
#include <QContextMenuEvent>
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>

QTimer *updateTime;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"init";
//set background transparent
    setAttribute(Qt::WA_TranslucentBackground,true);
//timeLabel
    updateTime =new QTimer(this);
    updateTime->setInterval(1000);
    connect(updateTime,SIGNAL(timeout()),this,SLOT(updateCurrentTime()));
    updateTime->start();
//click
//    addAction(new QAction("new",this));
//    addAction(new QAction("edit",this));
//   addAction(new QAction("delete",this));
//   setContextMenuPolicy(Qt::ActionsContextMenu);

    QAction *myDialogAct;
    myDialogAct =new QAction(tr("欢迎&HelloQT"),this);
    connect(myDialogAct, SIGNAL(triggered()), this, SLOT(welcome()));
    addAction(myDialogAct);

    QAction *wizardAct;
    wizardAct =new QAction(tr("向导&Wizard"),this);
    connect(wizardAct, SIGNAL(triggered()), this, SLOT(wizard()));
    addAction(wizardAct);

    QAction *aboutAct;
    aboutAct =new QAction(tr("关于&About"),this);
//    aboutAct->setStatusTip(tr("Show the application‘s About box"));//show in Status bar
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
    addAction(aboutAct);

/*
    QAction *snapAct;
    snapAct =new QAction(tr("snap"),this);
//    aboutAct->setStatusTip(tr("Show the application‘s About box"));//show in Status bar
    connect(snapAct, SIGNAL(triggered()), this, SLOT(snap()));
    addAction(snapAct);
*/
    setContextMenuPolicy(Qt::ActionsContextMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCurrentTime(){
    //    qDebug()<<"update Time!!!!";
    QDateTime currentTime = QDateTime::currentDateTime();
    QString stringTime = currentTime.toString("yyyy-MM-dd hh:mm:ss  ");
    ui->timeLabel->setText(stringTime);
    ui->timeLabel->update();
}

void MainWindow::about()
{
    qDebug()<<"about";
/*
    QDialog *dialog = new QDialog(this);
    dialog->setModal(true);
    dialog->show();
*/
/*
    QDialog dia;
    dia.exec();
*/
/*
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("文件对话框"),
                                                          "D:", tr("图片文件(*png *jpg)"));
    qDebug()<< "fileNames:" << fileNames;
*/
    // 关于对话框
    QMessageBox::about(this, tr("关于对话框"),
                       tr(" 版本：QT5.12.7\r\n 设备：海思Hi35xx DVR/NVR     \r\n 淘宝店铺：海思开发板总店"));
}


QWizardPage * MainWindow::createPage1()  // 向导页面1
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("第一步"));
    return page;
}
QWizardPage * MainWindow::createPage2()  // 向导页面2
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("第二步"));
    return page;
}
QWizardPage * MainWindow::createPage3()  // 向导页面3
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("结束"));
    return page;
}

// 向导对话框
void MainWindow::wizard()
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("向导对话框"));
    wizard.addPage(createPage1());     // 添加向导页面
    wizard.addPage(createPage2());
    wizard.addPage(createPage3());
    wizard.exec();
}

void MainWindow::snap()
{
    QScreen *screen = QGuiApplication::primaryScreen();

    QString filePathName = "full-";

    filePathName += QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss-zzz");

    filePathName += ".jpg";

    if(!screen->grabWindow(0).save(filePathName, "jpg"))

    {

        qDebug()<<"save full screen failed"<<endl;

    }
}

