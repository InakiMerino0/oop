#include <QCoreApplication>
#include <QElapsedTimer>
#include <QDebug>
#include "sensor.h"

const int REPETICIONES = 10000000;

int main() {
    QCoreApplication a(__argc, __argv);

    Sensor sensor;

    QElapsedTimer timer;

    // Inline implícito
    timer.start();
    volatile int suma1 = 0;
    for (int i = 0; i < REPETICIONES; ++i)
        suma1 += sensor.getValorBruto();
    qDebug() << "Tiempo getValorBruto (inline implícito):" << timer.elapsed() << "ms";

    // Offline
    timer.restart();
    volatile int suma2 = 0;
    for (int i = 0; i < REPETICIONES; ++i)
        suma2 += sensor.getValorBrutoOffline();
    qDebug() << "Tiempo getValorBrutoOffline (función normal):" << timer.elapsed() << "ms";

    // Inline explícito
    timer.restart();
    volatile double suma3 = 0;
    for (int i = 0; i < REPETICIONES; ++i)
        suma3 += sensor.getValorNormalizado();
    qDebug() << "Tiempo getValorNormalizado (inline explícito):" << timer.elapsed() << "ms";

    // Offline normal
    timer.restart();
    volatile double suma4 = 0;
    for (int i = 0; i < REPETICIONES; ++i)
        suma4 += sensor.getValorNormalizadoOffline();
    qDebug() << "Tiempo getValorNormalizadoOffline (función normal):" << timer.elapsed() << "ms";

    return 0;
}
