QT       += core gui xml x11extras dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = qtvkbd
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -lX11 -lXtst

SOURCES += \
    src/dragwidget.cpp \
    src/kbddock.cpp \
    src/kbdtray.cpp \
    src/keysymconvert.cpp \
    src/qtvkbdapp.cpp \
    src/main.cpp \
    src/mainwidget.cpp \
    src/resizabledragwidget.cpp \
    src/themeloader.cpp \
    src/vbutton.cpp \
    src/vkeyboard.cpp \
    src/x11keyboard.cpp \
    src/sliderdialog.cpp

HEADERS  += \
    src/dragwidget.h \
    src/kbddock.h \
    src/kbdtray.h \
    src/keysymconvert.h \
    src/qtvkbdapp.h \
    src/mainwidget.h \
    src/resizabledragwidget.h \
    src/themeloader.h \
    src/vbutton.h \
    src/vkeyboard.h \
    src/x11keyboard.h \
    src/sliderdialog.h

FORMS    +=

RESOURCES += \
    src/resources.qrc
