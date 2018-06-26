#include "dialog.h"
#include "loginform.h"
#include "ui_loginform.h"
#include "quiwidget.h"

#include <QGridLayout>


LoginForm::LoginForm(QWidget *parent) :
    MoveableFramelessWindow(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);

//    IconHelper::Instance()->setIcon(ui->labTitle, QChar(0xf0d1), 35);
//    IconHelper::Instance()->setIcon(ui->btnMenu_Min, QChar(0xF068));
//    IconHelper::Instance()->setIcon(ui->btnMenu_Max, QChar(0xF067));
//    IconHelper::Instance()->setIcon(ui->btnMenu_Close, QChar(0xF00d));

//    ui->label->setPixmap(QPixmap(QString::fromUtf8(":/tog.png")));
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
