QT += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Descargador
TEMPLATE = app

SOURCES += \
    main.cpp \
    downloader.cpp

HEADERS += \
    main.h \
    downloader.h

FORMS += \
    downloader.ui
