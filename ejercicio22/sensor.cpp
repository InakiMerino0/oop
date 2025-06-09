#include "sensor.h"

Sensor::Sensor() {
    valorActual = std::rand() % 1024; // aleatorio entre 0 y 1023
}

int Sensor::getValorBrutoOffline() const {
    return valorActual;
}

double Sensor::getValorNormalizadoOffline() const {
    return static_cast<double>(valorActual) / 1023.0;
}
