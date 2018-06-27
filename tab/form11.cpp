#include "form11.h"
#include "ui_form11.h"
#include <controller/database.h>

Form11::Form11(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form11)
{
    ui->setupUi(this);
}

Form11::~Form11()
{
    delete ui;
}

void Form11::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::database("connection");
    QSqlQuery query(db);
    QString text;
    query.exec("select  * from provider");
    while(query.next())
    {
        text = query.value(0).toString()+query.value(1).toString()+ query.value(2).toString() +query.value(3).toString();
        ui->textEdit->setText(text);
    }

}
