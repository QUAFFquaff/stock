#include "form41.h"
#include "ui_form41.h"

Form41::Form41(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form41)
{
    ui->setupUi(this);
}

Form41::~Form41()
{
    delete ui;
}
