#include "widget.h"
#include "pintura.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Pintura ventana;
    ventana.resize(800, 600);
    ventana.setWindowTitle("Pintura");
    ventana.show();

    return a.exec();
}
