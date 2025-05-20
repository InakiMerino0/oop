#include "CajaMedicamento.h"

// Ctor por defecto
CajaMedicamento::CajaMedicamento()
    : m_id(-1), m_dosis(0.0f)
{}

// Ctor sin ID
CajaMedicamento::CajaMedicamento(float dosis)
    : m_id(-1), m_dosis(dosis)
{}

// Ctor con ID
CajaMedicamento::CajaMedicamento(int id, float dosis)
    : m_id(id), m_dosis(dosis)
{}

// Suma de dosis
CajaMedicamento CajaMedicamento::operator+(const CajaMedicamento &otra) const {
    return CajaMedicamento(-1, m_dosis + otra.m_dosis);
}

// Comparación exacta de dosis
bool CajaMedicamento::operator==(const CajaMedicamento &otra) const {
    return m_dosis == otra.m_dosis;
}

// Texto formateado
QString CajaMedicamento::toString() const {
    return QString("CajaMedicamento [ID: %1, Dosis: %2]")
    .arg(m_id)
        .arg(m_dosis);
}
