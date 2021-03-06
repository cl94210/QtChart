#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtCharts>
using namespace QtCharts;
//QT_CHARTS_USE_NAMESPACE
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void CreateChart();

private:
    Ui::MainWindow *ui;
    int number;
    int count;
    QString str;
};
#endif // MAINWINDOW_H
