#ifndef CAJAMEDICAMENTO_H
#define CAJAMEDICAMENTO_H

#include <QString>

class CajaMedicamento {
public:
    // Constructor sin ID (para insertar)
    explicit CajaMedicamento(float dosis);

    // Constructor con ID (para cargar desde BD)
    CajaMedicamento(int id, float dosis);

    // Operadores
    CajaMedicamento operator+(const CajaMedicamento &otra) const;
    bool operator==(const CajaMedicamento &otra) const;

    QString toString() const;

    int id() const { return m_id; }
    float dosis() const { return m_dosis; }

private:
    int   m_id;
    float m_dosis;
};

#endif // CAJAMEDICAMENTO_H
