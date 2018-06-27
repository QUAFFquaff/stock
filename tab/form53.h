#ifndef FORM53_H
#define FORM53_H

#include <QWidget>

namespace Ui {
class Form53;
}

class Form53 : public QWidget
{
    Q_OBJECT

public:
    explicit Form53(QWidget *parent = 0);
    ~Form53();

private:
    Ui::Form53 *ui;
};

#endif // FORM53_H
