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
    void load();
    void save();

protected:

      QWidget*getDragnWidget();
private slots:
    /**
     * @brief 登录按钮点击
     */
    void doLoginButClick();

    void on_btnMenu_Min_clicked();

    void on_btnMenu_Close_clicked();

    /**
     *
     * 记住密码
     */
    bool writeInit(QString path,QString user_key,QString user_value);
    bool readInit(QString path,QString user_key,QString &user_value);
    bool rememberPass();
private:
    Ui::LoginForm *ui;
};

#endif // LOGINFORM_H
