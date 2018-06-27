#include "form31.h"
#include "ui_form31.h"

Form31::Form31(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form31)
{
    ui->setupUi(this);
}

Form31::~Form31()
{
    delete ui;
}
