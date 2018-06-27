#ifndef FORM52_H
#define FORM52_H

#include <QWidget>

namespace Ui {
class Form52;
}

class Form52 : public QWidget
{
    Q_OBJECT

public:
    explicit Form52(QWidget *parent = 0);
    ~Form52();

private:
    Ui::Form52 *ui;
};

#endif // FORM52_H
