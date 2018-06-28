#include "dialog.h"
#include "ui_dialog.h"
#include "sliderbar.h"
#include "quiwidget.h"
#include "qtimer.h"
#include "qdebug.h"
#include <qcustomplot.h>
#include <qstackedwidget.h>
#include <controller/database.h>
#include <controller/draw.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->initForm();
    QUIWidget::setFormInCenter(this);
    QTimer::singleShot(100, this, SLOT(initIndex()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::initForm()
{

    this->max = false;
    this->location = this->geometry();
    this->setProperty("form", true);
    this->setProperty("canMove", true);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    this->setWindowTitle("智能物流管理平台");

    IconHelper::Instance()->setIcon(ui->labTitle, QChar(0xf0d1), 35);
    IconHelper::Instance()->setIcon(ui->btnMenu_Min, QChar(0xF068));
    IconHelper::Instance()->setIcon(ui->btnMenu_Max, QChar(0xF067));
    IconHelper::Instance()->setIcon(ui->btnMenu_Close, QChar(0xF00d));

    QString items = "职工管理;进货商管理";
    ui->widgetNavLeft->setItems(items);
    ui->widgetNavLeft->setHorizontal(false);
    ui->widgetNavLeft->setLineWidth(5);
    ui->widgetNavLeft->setLineColor(QColor("#029FEA"));
    ui->widgetNavLeft->setBgColorStart(QColor("#292F38"));
    ui->widgetNavLeft->setBgColorEnd(QColor("#292F38"));
    ui->widgetNavLeft->setBarColorStart(QColor("#1D2025"));
    ui->widgetNavLeft->setBarColorEnd(QColor("#1D2025"));
    ui->widgetNavLeft->setTextNormalColor(QColor("#54626F"));
    ui->widgetNavLeft->setTextSelectColor(QColor("#FDFDFD"));
    ui->widgetNavLeft->setBarStyle(SliderBar::BarStyle_Line_Left);

    items = "人事管理;销售管理;进货管理;库存管理;系统管理";
    ui->widgetNavTop->setItems(items);
    ui->widgetNavTop->setHorizontal(true);
    ui->widgetNavTop->setLineWidth(5);
    ui->widgetNavTop->setSpace(100);
    ui->widgetNavTop->setLineColor(QColor("#1CA0E4"));
    ui->widgetNavTop->setBgColorStart(QColor("#FFFFFF"));
    ui->widgetNavTop->setBgColorEnd(QColor("#FFFFFF"));
    ui->widgetNavTop->setBarColorStart(QColor("#FAFBFD"));
    ui->widgetNavTop->setBarColorEnd(QColor("#FAFBFD"));
    ui->widgetNavTop->setTextNormalColor(QColor("#6D7173"));
    ui->widgetNavTop->setTextSelectColor(QColor("#6D7173"));
    ui->widgetNavTop->setBarStyle(SliderBar::BarStyle_Line_Bottom);
    //tableWidget自适应列宽行高
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //连接菜单槽函数
    connect(ui->widgetNavLeft, SIGNAL(currentItemChanged(int, QString)),this, SLOT(leftItemChanged(int, QString)));
    connect(ui->widgetNavTop, SIGNAL(currentItemChanged(int, QString)),this, SLOT(topItemChanged(int, QString)));
}

void Dialog::initIndex()
{
    ui->widgetNavLeft->setCurrentIndex(0);
    ui->widgetNavTop->setCurrentIndex(0);
}

void Dialog::topItemChanged(int , const QString &item)
{
    ui->widgetNavLeft->moveFirst();
    if(item == "人事管理"){
        ui->widgetNavLeft->setItems("职工管理;进货商管理");
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if(item == "销售管理"){
        ui->widgetNavLeft->setItems("销售记录管理;销售统计");
        ui->stackedWidget->setCurrentIndex(2);
    }
    else if(item == "进货管理"){
        ui->widgetNavLeft->setItems("进货记录管理");
        ui->stackedWidget->setCurrentIndex(4);
    }
    else if(item == "库存管理"){
        ui->widgetNavLeft->setItems("商品管理");
        ui->stackedWidget->setCurrentIndex(5);
    }
    else if(item == "系统管理"){
        ui->widgetNavLeft->setItems("添加管理员;修改资料;修改密码");
        ui->stackedWidget->setCurrentIndex(6);
    }
}

void Dialog::leftItemChanged(int, const QString &item)
{
    //左侧菜单函数
    if(item == "职工管理"){
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if(item == "进货商管理"){
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if(item == "销售记录管理"){
        ui->stackedWidget->setCurrentIndex(2);
    }
    else if(item == "销售统计"){
        Draw *d = new Draw;
        d->drawPlot(this->ui->page_4);
        ui->stackedWidget->setCurrentIndex(3);
    }
    else if(item == "进货记录管理"){
        ui->stackedWidget->setCurrentIndex(4);
    }
    else if(item == "商品管理"){
        ui->stackedWidget->setCurrentIndex(5);
    }
    else if(item == "添加管理员"){
        ui->stackedWidget->setCurrentIndex(6);
    }
    else if(item == "修改资料"){
        ui->stackedWidget->setCurrentIndex(7);
    }
    else if(item == "修改密码"){
        draw();
        ui->stackedWidget->setCurrentIndex(8);
    }
}

void Dialog::on_btnMenu_Min_clicked()
{
    showMinimized();
}

void Dialog::on_btnMenu_Max_clicked()
{
    if (max) {
        this->setGeometry(location);
        this->setProperty("canMove", true);
    } else {
        location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
        this->setProperty("canMove", false);
    }
    max = !max;
}

void Dialog::on_btnMenu_Close_clicked()
{
    close();
}

void Dialog::on_pushButton_clicked()
{
//    QSqlDatabase db = QSqlDatabase::database("connection");
//    QSqlQuery query(db);
//    int i=0,j=0,nCol,nRow;
//    query.exec("select  * from provider");
//    query.last();
//    nRow=query.at();
//    nCol = ui->tableWidget->columnCount();
//    query.first();
//    while(j<nRow)
//    {
//        for(i=0;i<nCol;i++){
//            ui->tableWidget->setItem(j,i,new QTableWidgetItem(query.value(i).toString()) );
//            j++;
//            query.next();
//        }
//    }
    //    db.close();
}

void Dialog::draw()
{
    // prepare data:
    QVector<double> x1(20), y1(20);
    QVector<double> x2(100), y2(100);
    QVector<double> x3(20), y3(20);
    QVector<double> x4(20), y4(20);
    for (int i=0; i<x1.size(); ++i)
    {
      x1[i] = i/(double)(x1.size()-1)*10;
      y1[i] = qCos(x1[i]*0.8+qSin(x1[i]*0.16+1.0))*qSin(x1[i]*0.54)+1.4;
    }
    for (int i=0; i<x2.size(); ++i)
    {
      x2[i] = i/(double)(x2.size()-1)*10;
      y2[i] = qCos(x2[i]*0.85+qSin(x2[i]*0.165+1.1))*qSin(x2[i]*0.50)+1.7;
    }
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i/(double)(x3.size()-1)*10;
      y3[i] = 0.05+3*(0.5+qCos(x3[i]*x3[i]*0.2+2)*0.5)/(double)(x3[i]+0.7)+qrand()/(double)RAND_MAX*0.01;
    }
    for (int i=0; i<x4.size(); ++i)
    {
      x4[i] = x3[i];
      y4[i] = (0.5-y3[i])+((x4[i]-2)*(x4[i]-2)*0.02);
    }

    // create and configure plottables:
    QCPGraph *graph1 = this->ui->customPlot->addGraph();
    graph1->setData(x1, y1);
    graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    graph1->setPen(QPen(QColor(120, 120, 120), 2));

    QCPGraph *graph2 = ui->customPlot->addGraph();
    graph2->setData(x2, y2);
    graph2->setPen(Qt::NoPen);
    graph2->setBrush(QColor(200, 200, 200, 20));
    graph2->setChannelFillGraph(graph1);

    QCPBars *bars1 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    bars1->setWidth(9/(double)x3.size());
    bars1->setData(x3, y3);
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(10, 140, 70, 160));

    QCPBars *bars2 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    bars2->setWidth(9/(double)x4.size());
    bars2->setData(x4, y4);
    bars2->setPen(Qt::NoPen);
    bars2->setBrush(QColor(10, 100, 50, 70));
    bars2->moveAbove(bars1);

    // move bars above graphs and grid below bars:
    ui->customPlot->addLayer("abovemain", ui->customPlot->layer("main"), QCustomPlot::limAbove);
    ui->customPlot->addLayer("belowmain", ui->customPlot->layer("main"), QCustomPlot::limBelow);
    graph1->setLayer("abovemain");
    ui->customPlot->xAxis->grid()->setLayer("belowmain");
    ui->customPlot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    ui->customPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    ui->customPlot->axisRect()->setBackground(axisRectGradient);

    ui->customPlot->rescaleAxes();
    ui->customPlot->yAxis->setRange(0, 2);
    ui->customPlot->show();
    ui->customPlot->replot();
}
