#include "dialog.h"
#include "loginform.h"
#include "ui_loginform.h"
#include "quiwidget.h"
#include "demo/appinit.h"

#include <QGridLayout>
#include <qsqldatabase.h>
#include <qsqlquery.h>


LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
//    load();
    this->setProperty("canMove", true);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    setAttribute(Qt::WA_TranslucentBackground);
    QUIWidget::setFormInCenter(this);
    IconHelper::Instance()->setIcon(ui->btnMenu_Min, QChar(0xF068));
    IconHelper::Instance()->setIcon(ui->btnMenu_Close, QChar(0xF00d));



        QString username;
        QString password;
        QString rem_state;
        QString auto_state;
        bool is_un = readInit(QString("./user.ini"), "username", username);
        bool is_pass = readInit(QString("./user.ini"), "password", password);
        readInit(QString("./user.ini"), "remember_states", rem_state);
        readInit(QString("./user.ini"), "auto_states", auto_state);
        ui->lineEdit_un->setText(username);
        ui->lineEdit_pass->setText(password);
        ui->checkBox->setChecked(rem_state=="1");
        ui->checkBox_2->setChecked(auto_state=="1");
    if(ui->checkBox_2->isChecked()){

        doLoginButClick();
    }


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
    QString strPwd5 = ui->lineEdit_pass->text();
    if(NULL == strPwd5)
        return;

    QByteArray bytePwd = strPwd5.toLatin1();
    QByteArray bytePwdMd5 = QCryptographicHash::hash(bytePwd, QCryptographicHash::Md5);
    QString strPwdMd5 = bytePwdMd5.toHex();
//    ui->lineEdit_pass->setText(strPwdMd5);
    qDebug()<<strPwdMd5<<"    "<<bytePwdMd5<<endl;


    QSqlDatabase db = QSqlDatabase::database("connection");
    QSqlQuery query(db);
    QString text;
//    query.exec("insert into employee values(000,\"Izerille\",\"ez\",\"5f4dcc3b5aa765d61d8327deb882cf99\",0,\"33040319980520661x\","
//               "6000,9,\"2016-10-11\",\"1998-05-20\",\"boss\") ");
    query.exec("select * from employee where username = \""+ui->lineEdit_un->text()+"\"");
    while(query.next())
    {
        qDebug()<<query.value(3);
        text = query.value(3).toString();
    }


    if (text == strPwdMd5){
        rememberPass();
        Dialog *d = new Dialog;
        d->show();
    }else{
        qDebug()<<"wrong password";
    }

}

void LoginForm::on_btnMenu_Min_clicked()
{
    showMinimized();
}

void LoginForm::on_btnMenu_Close_clicked()
{
    close();
}



bool LoginForm::writeInit(QString path, QString user_key, QString user_value)
{
    if(path.isEmpty() || user_key.isEmpty()){
        return false;
    }
    else{
        //创建文件
        QSettings * config =  new QSettings(path,QSettings::IniFormat);

        //写入
        config->beginGroup("config");
        config->setValue(user_key,user_value);
        config->endGroup();
        return true;
    }
}

bool LoginForm::readInit(QString path, QString user_key, QString &user_value)
{
    user_value = QString("");
    if(path.isEmpty() || user_key.isEmpty()){
        return false;
    }
    else{
        //创建操作对象
        QSettings * config = new QSettings(path,QSettings::IniFormat);

        //读取
        user_value = config->value(QString("config/") + user_key).toString();
        return true;
    }
}

bool LoginForm::rememberPass()
{
    if(ui->checkBox->isChecked()){
        qDebug()<<"checked";
        QString username = ui->lineEdit_un->text();  //账号
        QString password = ui->lineEdit_pass->text();  //密码

        bool is_address = writeInit(QString("./user.ini"), "username", username);
        bool is_port = writeInit(QString("./user.ini"), "password", password);

    }
    else{
        bool is_address = writeInit(QString("./user.ini"), "username", "");
        bool is_port = writeInit(QString("./user.ini"), "password", "");

        qDebug()<<"not checked";
    }

    writeInit(QString("./user.ini"), "remember_states", QString::number(ui->checkBox->isChecked()));
    writeInit(QString("./user.ini"), "auto_states", QString::number(ui->checkBox_2->isChecked()));

}

void LoginForm::on_checkBox_2_clicked(bool checked)
{
    if(!ui->checkBox->isChecked() && ui->checkBox_2->isChecked()){
        ui->checkBox->setChecked(true);
    }
}

void LoginForm::on_checkBox_clicked()
{
    if(!ui->checkBox->isChecked() && ui->checkBox_2->isChecked()){
        ui->checkBox_2->setChecked(false);
    }
}
