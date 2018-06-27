#ifndef FORM22_H
#define FORM22_H

#include <QWidget>

namespace Ui {
class Form22;
}

class Form22 : public QWidget
{
    Q_OBJECT

public:
    explicit Form22(QWidget *parent = 0);
    ~Form22();

private:
    Ui::Form22 *ui;
};

#endif // FORM22_H
