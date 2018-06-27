#include "form53.h"
#include "ui_form53.h"

Form53::Form53(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form53)
{
    ui->setupUi(this);
}

Form53::~Form53()
{
    delete ui;
}
