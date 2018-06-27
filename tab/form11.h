#ifndef FORM11_H
#define FORM11_H

#include <QWidget>

namespace Ui {
class Form11;
}

class Form11 : public QWidget
{
    Q_OBJECT

public:
    explicit Form11(QWidget *parent = 0);
    ~Form11();

private:
    Ui::Form11 *ui;
};

#endif // FORM11_H
