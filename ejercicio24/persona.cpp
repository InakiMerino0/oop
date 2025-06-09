#include "persona.h"
#include <iostream>

int Persona::contador = 0; // inicialización del atributo estático

Persona::Persona(const QString& nombre) : nombre(nombre) {
    ++contador;
}

void Persona::mostrar() const {
    std::cout << "Nombre: " << nombre.toStdString() << std::endl;
}

int Persona::totalPersonas() {
    return contador;
}
