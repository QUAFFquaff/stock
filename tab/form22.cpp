#include "form22.h"
#include "ui_form22.h"

Form22::Form22(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form22)
{
    ui->setupUi(this);
}

Form22::~Form22()
{
    delete ui;
}
