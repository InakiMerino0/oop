#ifndef PERSONA_H
#define PERSONA_H

#include <QString>

class Persona {
private:
    QString nombre;
    static int contador;  // atributo estático

public:
    Persona(const QString& nombre);
    void mostrar() const;
    static int totalPersonas(); // método estático
};

#endif // PERSONA_H
