#include "form52.h"
#include "ui_form52.h"

Form52::Form52(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form52)
{
    ui->setupUi(this);
}

Form52::~Form52()
{
    delete ui;
}
