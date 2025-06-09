#include <QApplication>
#include <vector>
#include "guitarra.h"
#include "bateria.h"
#include "teclado.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    vector<Instrumento*> instrumentos;

    // Crear objetos y agregarlos al vector
    instrumentos.push_back(new Guitarra);
    instrumentos.push_back(new Bateria);
    instrumentos.push_back(new Teclado);
    instrumentos.push_back(new Guitarra);
    instrumentos.push_back(new Teclado);

    // Recorrer el vector e invocar métodos virtuales
    for (Instrumento* inst : instrumentos) {
        inst->verlo();
        inst->sonar();
        qDebug() << "----------------------";
    }

    // Liberar memoria
    for (Instrumento* inst : instrumentos) {
        delete inst;  // Si es Teclado, se verá "Desenchufado"
    }

    return 0;
}
