#include "form11.h"
#include "ui_form11.h"

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
