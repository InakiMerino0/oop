#include <QCoreApplication>
#include <iostream>
#include "persona.h"

int main() {
    Persona p1("Ana");
    Persona p2("Luis");
    Persona p3("Carla");
    Persona p4("Juan");

    p1.mostrar();
    p2.mostrar();
    p3.mostrar();
    p4.mostrar();
    std::cout << "Total de personas creadas: " << Persona::totalPersonas() << std::endl;

    return 0;
}
