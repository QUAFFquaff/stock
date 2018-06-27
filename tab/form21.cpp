#include "form21.h"
#include "ui_form21.h"

Form21::Form21(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form21)
{
    ui->setupUi(this);
}

Form21::~Form21()
{
    delete ui;
}
