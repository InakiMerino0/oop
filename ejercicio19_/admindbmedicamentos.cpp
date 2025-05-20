#include "AdminDBMedicamentos.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

AdminDBMedicamentos* AdminDBMedicamentos::s_inst = nullptr;

AdminDBMedicamentos* AdminDBMedicamentos::instancia() {
    if (!s_inst) {
        s_inst = new AdminDBMedicamentos();
    }
    return s_inst;
}

AdminDBMedicamentos::AdminDBMedicamentos() {}

void AdminDBMedicamentos::conectar() {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("medicamentos.db");
    if (!m_db.open()) {
        qDebug() << "Error al abrir BD:" << m_db.lastError().text();
    }
    QSqlQuery q;
    q.exec("CREATE TABLE IF NOT EXISTS cajas_medicamentos ("
           "id INTEGER PRIMARY KEY AUTOINCREMENT, "
           "dosis_totales REAL NOT NULL)");
}

bool AdminDBMedicamentos::insertarCaja(float dosis) {
    float total = obtenerTotalDosis();
    if (total + dosis > 1000.0f)
        return false;

    QSqlQuery q(m_db);
    q.prepare("INSERT INTO cajas_medicamentos(dosis_totales) VALUES(?)");
    q.addBindValue(dosis);
    return q.exec();
}

QList<CajaMedicamento> AdminDBMedicamentos::obtenerTodas() {
    QList<CajaMedicamento> lista;
    QSqlQuery q(m_db);
    q.exec("SELECT id, dosis_totales FROM cajas_medicamentos");
    while (q.next()) {
        int id   = q.value(0).toInt();
        float d  = q.value(1).toFloat();
        lista.append(CajaMedicamento(id, d));
    }
    return lista;
}

float AdminDBMedicamentos::obtenerTotalDosis() {
    QSqlQuery q(m_db);
    q.exec("SELECT SUM(dosis_totales) FROM cajas_medicamentos");
    if (q.next())
        return q.value(0).toFloat();
    return 0.0f;
}
