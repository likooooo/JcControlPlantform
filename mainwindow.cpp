#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /** Region:注册事件
     * **/

    connect(ui->actionCreateSln, SIGNAL(triggered()), this, SLOT(on_actionCreateSln_triggered()));

    /** EndRegion
     * **/



    //设置Title
    this->setWindowTitle("this->setWindowTitle");
    //设置ico
    this->setWindowIcon(QIcon("A:/Qt/Tools/QtCreator/share/qtcreator/qbs/share/qbs/examples/cocoa-application/CocoaApplication/dmg.iconset/icon_32x32.png"));
    //设置窗体最大化
    this->setWindowState(Qt::WindowMaximized);
}

void MainWindow::TriggerTest()
{
    this->setWindowState(Qt::WindowMinimized);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionCreateSln_triggered()
{

     QString filePath = "G:/Code/jcdz/JcControlPlantform/Bin/debug/testSln.cpSln";
     QString slnName = "testSln";

     Sln* sln = new Sln();
     sln->SetSlnConfigFilePath(filePath);
     sln->SetSlnName(slnName);
     sln->Save();
//    Sln* sln = new Sln(filePath,slnName);
//    sln->Save();
}
