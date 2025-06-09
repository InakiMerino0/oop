QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bateria.cpp \
    electrico.cpp \
    guitarra.cpp \
    main.cpp \
    instrumento.cpp \
    teclado.cpp

HEADERS += \
    bateria.h \
    electrico.h \
    guitarra.h \
    instrumento.h \
    teclado.h

FORMS += \
    instrumento.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
