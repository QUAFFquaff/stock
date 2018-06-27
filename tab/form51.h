#ifndef FORM51_H
#define FORM51_H

#include <QWidget>

namespace Ui {
class Form51;
}

class Form51 : public QWidget
{
    Q_OBJECT

public:
    explicit Form51(QWidget *parent = 0);
    ~Form51();

private:
    Ui::Form51 *ui;
};

#endif // FORM51_H
