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
    CreateChart();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreateChart()
{
    //创建图表
    QChartView *m_chartView=new QChartView(this);
    QChart *m_chart=new QChart();
    m_chart->setTitle("简单函数曲线");
    m_chartView->setChart(m_chart);
    this->setCentralWidget(m_chartView);
    //创建折线序列
    QLineSeries *m_series0=new QLineSeries();
    QLineSeries *m_series1=new QLineSeries();
    QLineSeries *m_series2=new QLineSeries();
    QLineSeries *m_series3=new QLineSeries();
    m_series0->setName("Sin 曲线");
    m_series1->setName("Cos 曲线");
    m_series2->setName("直线");
    //序列添加到图表
    m_chart->addSeries(m_series0);
    m_chart->addSeries(m_series1);
    m_chart->addSeries(m_series2);
    m_chart->addSeries(m_series3);
    //给序列添加数值
    qreal t=0,y1,y2,intv=0.1;
    int cnt=200;
    for(int i=0;i<cnt;i++)
    {
        y1=qSin(t);//+qrand();
        m_series0->append(t,y1);
        y2=qSin(t+20);
        m_series1->append(t,y2);
        t+=intv;
    }
    m_series2->append(0,-2);
    m_series2->append(20,2);
    m_series3->append(0,2);
    m_series3->append(20,-2);
    //创建坐标轴
    QValueAxis *m_axisX=new QValueAxis;
    m_axisX->setRange(0,20);
    m_axisX->setTitleText("time(secs)");

    QValueAxis *m_axisY=new QValueAxis;
    m_axisY->setRange(-2,2);
    m_axisY->setTitleText("value");

    //为序列设置坐标轴
    m_chart->setAxisX(m_axisX,m_series0);
    m_chart->setAxisY(m_axisY,m_series0);
    m_chart->setAxisX(m_axisX,m_series1);
    m_chart->setAxisY(m_axisY,m_series1);
    m_chart->setAxisX(m_axisX,m_series2);
    m_chart->setAxisY(m_axisY,m_series2);
    m_chart->setAxisX(m_axisX,m_series3);
    m_chart->setAxisY(m_axisY,m_series3);

}

