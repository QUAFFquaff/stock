#include "form51.h"
#include "ui_form51.h"

Form51::Form51(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form51)
{
    ui->setupUi(this);
}

Form51::~Form51()
{
    delete ui;
}
