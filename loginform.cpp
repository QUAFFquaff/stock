#include "dialog.h"
#include "loginform.h"
#include "ui_loginform.h"
#include "quiwidget.h"
#include "demo/appinit.h"

#include <QGridLayout>


LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);

    this->setProperty("canMove", true);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    setAttribute(Qt::WA_TranslucentBackground);
    QUIWidget::setFormInCenter(this);
    IconHelper::Instance()->setIcon(ui->btnMenu_Min, QChar(0xF068));
    IconHelper::Instance()->setIcon(ui->btnMenu_Close, QChar(0xF00d));

    //关联登录按钮点击
    connect(ui->pushButton_login,SIGNAL(clicked()),this,SLOT(doLoginButClick()));
}

LoginForm::~LoginForm()
{
    delete ui;
}

QWidget *LoginForm::getDragnWidget()
{
    return ui->login_top_widget;
}

void LoginForm::doLoginButClick()
{
//    this->hide();
    Dialog *d = new Dialog;
    d->show();

}

void LoginForm::on_btnMenu_Min_clicked()
{
    showMinimized();
}

void LoginForm::on_btnMenu_Close_clicked()
{
    close();
}
