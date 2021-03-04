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
}

MainWindow::~MainWindow()
{
    delete ui;
}

