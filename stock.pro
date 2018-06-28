#-------------------------------------------------
#
# Project created by QtCreator 2018-06-23T11:28:51
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET          = stock
TEMPLATE        = app
MOC_DIR         = temp/moc
RCC_DIR         = temp/rcc
UI_DIR          = temp/ui
OBJECTS_DIR     = temp/obj
#DESTDIR         = $$PWD/bin
win32:RC_FILE   = other/main.rc
PRECOMPILED_HEADER  = head.h

INCLUDEPATH     += $$PWD
INCLUDEPATH     += $$PWD/form
INCLUDEPATH     += $$PWD/demo
CONFIG          += qt warn_off
DEFINES         += demo1

SOURCES += main.cpp\
    loginform.cpp \
    form/quiwidget.cpp \
    demo/sliderbar.cpp \
    dialog.cpp \
    demo/appinit.cpp \
    entity/employee.cpp \
    controller/salecontroller.cpp \
    controller/util.cpp \
    entity/provider.cpp \
    entity/product.cpp \
    entity/sale.cpp \
    entity/purchase.cpp \
    controller/saleutil.cpp \
    controller/productutil.cpp \
    controller/providerutil.cpp \
    controller/purchaseutil.cpp \
    entity/user.cpp \
    demo/qcustomplot.cpp \
    controller/draw.cpp

HEADERS  += \
    loginform.h \
    head.h \
    form/quiwidget.h \
    dialog.h \
    demo/sliderbar.h \
    demo/appinit.h \
    tab/form11.h \
    tab/form12.h \
    entity/employee.h \
    controller/salecontroller.h \
    controller/util.h \
    entity/provider.h \
    entity/product.h \
    entity/sale.h \
    entity/purchase.h \
    controller/saleutil.h \
    controller/productutil.h \
    controller/providerutil.h \
    controller/purchaseutil.h \
    controller/database.h \
    entity/user.h \
    demo/qcustomplot.h \
    controller/draw.h

FORMS    += \
    loginform.ui \
    dialog.ui

RESOURCES += \
    other/font.qrc \
    other/pic.qrc \
    other/qss.qrc
