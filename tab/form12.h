#ifndef FORM12_H
#define FORM12_H

#include <QWidget>

namespace Ui {
class Form12;
}

class Form12 : public QWidget
{
    Q_OBJECT

public:
    explicit Form12(QWidget *parent = 0);
    ~Form12();

private:
    Ui::Form12 *ui;
};

#endif // FORM12_H
