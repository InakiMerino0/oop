#ifndef ADMINDBMEDICAMENTOS_H
#define ADMINDBMEDICAMENTOS_H

#include <QSqlDatabase>
#include <QList>
#include "CajaMedicamento.h"

class AdminDBMedicamentos {
public:
    static AdminDBMedicamentos* instancia();
    void conectar();
    bool insertarCaja(float dosis);
    QList<CajaMedicamento> obtenerTodas();
    float obtenerTotalDosis();

private:
    AdminDBMedicamentos();
    QSqlDatabase m_db;
    static AdminDBMedicamentos* s_inst;
};

#endif // ADMINDBMEDICAMENTOS_H
