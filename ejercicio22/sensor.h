#ifndef SENSOR_H
#define SENSOR_H

#include <cstdlib>

class Sensor {
private:
    int valorActual;

public:
    Sensor();

    // Inline implícito
    int getValorBruto() const { return valorActual; }

    // Offline (definido fuera de clase)
    int getValorBrutoOffline() const;

    // Inline explícito
    inline double getValorNormalizado() const { return valorActual / 1023.0; }

    // Offline (sin inline)
    double getValorNormalizadoOffline() const;
};

#endif // SENSOR_H
