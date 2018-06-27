#ifndef FORM21_H
#define FORM21_H

#include <QWidget>

namespace Ui {
class Form21;
}

class Form21 : public QWidget
{
    Q_OBJECT

public:
    explicit Form21(QWidget *parent = 0);
    ~Form21();

private:
    Ui::Form21 *ui;
};

#endif // FORM21_H
