void on_pushButton_clicked();
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}
class QStackedWidget;
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    bool max;
    QRect location;
    QStackedWidget *stackedWidget;

private slots:
    void initForm();
    void initIndex();
    void topItemChanged(int, const QString &item);
    void leftItemChanged(int, const QString &item);
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();
    void on_pushButton_clicked();
};

#endif // DIALOG_H
