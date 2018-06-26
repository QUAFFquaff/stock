#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>

namespace Ui {
class LoginForm;
}

class LoginForm :public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = 0);
    ~LoginForm();

protected:

      QWidget*getDragnWidget();
private slots:
    /**
     * @brief 登录按钮点击
     */
    void doLoginButClick();

    void on_btnMenu_Min_clicked();

    void on_btnMenu_Close_clicked();

private:
    Ui::LoginForm *ui;
};

#endif // LOGINFORM_H
