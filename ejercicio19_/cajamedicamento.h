#ifndef CAJAMEDICAMENTO_H
#define CAJAMEDICAMENTO_H

#include <QString>

class CajaMedicamento {
public:
    // Ctor por defecto (ID = –1, dosis = 0)
    CajaMedicamento();

    // Ctor para nueva caja (sin ID)
    explicit CajaMedicamento(float dosis);

    // Ctor para cargar desde BD (ID y dosis)
    CajaMedicamento(int id, float dosis);

    // Suma de dosis (devuelve nueva caja sin ID)
    CajaMedicamento operator+(const CajaMedicamento &otra) const;

    // Igualdad exacta de dosis
    bool operator==(const CajaMedicamento &otra) const;

    // Representación texto
    QString toString() const;

    // Getters
    int id()    const { return m_id; }
    float dosis() const { return m_dosis; }

private:
    int   m_id;
    float m_dosis;
};

#endif // CAJAMEDICAMENTO_H
