#include "form/quiwidget.h"
#include "dialog.h"
#include "demo/appinit.h"
#include <QApplication>
#include "login.h"
#include "loginform.h"

int main(int argc, char *argv[])
{
#if (QT_VERSION >= QT_VERSION_CHECK(5,6,0))
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication a(argc, argv);
    a.setFont(QFont("Microsoft Yahei", 11));
    a.setWindowIcon(QIcon(":/main.ico"));

    QUIWidget::setCode();
    AppInit::Instance()->start();
//    Dialog *d = new Dialog;
//    d->show();
    LoginForm *login = new LoginForm;
    login->show();
    return a.exec();
}
