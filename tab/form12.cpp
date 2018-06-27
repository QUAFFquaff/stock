#include "form12.h"
#include "ui_form12.h"

Form12::Form12(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form12)
{
    ui->setupUi(this);
}

Form12::~Form12()
{
    delete ui;
}
