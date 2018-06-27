﻿#include "dialog.h"
#include "ui_dialog.h"
#include "sliderbar.h"
#include "quiwidget.h"
#include "qtimer.h"
#include "qdebug.h"
#include <qstackedwidget.h>
#include <controller/database.h>
#include "tab/form11.h"
#include "tab/form12.h"
#include "tab/form21.h"
#include "tab/form22.h"
#include "tab/form31.h"
#include "tab/form41.h"
#include "tab/form51.h"
#include "tab/form52.h"
#include "tab/form53.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->initForm();
    QUIWidget::setFormInCenter(this);
    QTimer::singleShot(100, this, SLOT(initIndex()));
    stackedWidget = new QStackedWidget;
    ui->mainLayout->addWidget(stackedWidget);
    Form11 *f11 = new Form11;stackedWidget->addWidget(f11);
    Form12 *f12 = new Form12;stackedWidget->addWidget(f12);
    Form21 *f21 = new Form21;stackedWidget->addWidget(f21);
    Form22 *f22 = new Form22;stackedWidget->addWidget(f22);
    Form31 *f31 = new Form31;stackedWidget->addWidget(f31);
    Form41 *f41 = new Form41;stackedWidget->addWidget(f41);
    Form51 *f51 = new Form51;stackedWidget->addWidget(f51);
    Form52 *f52 = new Form52;stackedWidget->addWidget(f52);
    Form53 *f53 = new Form53;stackedWidget->addWidget(f53);
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
        stackedWidget->setCurrentIndex(0);
    }
    else if(item == "销售管理"){
        ui->widgetNavLeft->setItems("销售记录管理;销售统计");
        stackedWidget->setCurrentIndex(2);
    }
    else if(item == "进货管理"){
        ui->widgetNavLeft->setItems("进货记录管理");
        stackedWidget->setCurrentIndex(4);
    }
    else if(item == "库存管理"){
        ui->widgetNavLeft->setItems("商品管理");
        stackedWidget->setCurrentIndex(5);
    }
    else if(item == "系统管理"){
        ui->widgetNavLeft->setItems("添加管理员;修改资料;修改密码");
        stackedWidget->setCurrentIndex(6);
    }
}

void Dialog::leftItemChanged(int, const QString &item)
{
    //左侧菜单函数
    if(item == "职工管理"){
        stackedWidget->setCurrentIndex(0);
    }
    else if(item == "进货商管理"){
        stackedWidget->setCurrentIndex(1);
    }
    else if(item == "销售记录管理"){
        stackedWidget->setCurrentIndex(2);
    }
    else if(item == "销售统计"){
        stackedWidget->setCurrentIndex(3);
    }
    else if(item == "进货记录管理"){
        stackedWidget->setCurrentIndex(4);
    }
    else if(item == "商品管理"){
        stackedWidget->setCurrentIndex(5);
    }
    else if(item == "添加管理员"){
        stackedWidget->setCurrentIndex(6);
    }
    else if(item == "修改资料"){
        stackedWidget->setCurrentIndex(7);
    }
    else if(item == "修改密码"){
        stackedWidget->setCurrentIndex(8);
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
