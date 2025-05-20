QT       += core gui sql widgets
CONFIG   += c++11
TEMPLATE = app
SOURCES += \
    grafico.cpp \
    main.cpp \
    CajaMedicamento.cpp \
    AdminDBMedicamentos.cpp \
    widget.cpp
HEADERS += \
    CajaMedicamento.h \
    AdminDBMedicamentos.h \
    grafico.h \
    widget.h

FORMS += \
    grafico.ui
