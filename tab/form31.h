#ifndef FORM31_H
#define FORM31_H

#include <QWidget>

namespace Ui {
class Form31;
}

class Form31 : public QWidget
{
    Q_OBJECT

public:
    explicit Form31(QWidget *parent = 0);
    ~Form31();

private:
    Ui::Form31 *ui;
};

#endif // FORM31_H
