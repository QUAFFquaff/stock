#-------------------------------------------------
#
# Project created by QtCreator 2018-06-23T11:28:51
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET          = stock
TEMPLATE        = app
MOC_DIR         = temp/moc
RCC_DIR         = temp/rcc
UI_DIR          = temp/ui
OBJECTS_DIR     = temp/obj
DESTDIR         = $$PWD/bin
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
    moveableframelesswindow.cpp \
    demo/appinit.cpp

HEADERS  += \
    loginform.h \
    head.h \
    form/quiwidget.h \
    dialog.h \
    demo/sliderbar.h \
    moveableframelesswindow.h \
    demo/appinit.h

FORMS    += \
    loginform.ui \
    dialog.ui \

RESOURCES += \
    other/font.qrc \
    other/pic.qrc
