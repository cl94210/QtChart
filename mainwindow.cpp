#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    number=1;
    count=0;
    str="hello,world";
    qDebug()<<str<<endl;
    qDebug()<<number<<endl;
    qDebug()<<count<<endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

