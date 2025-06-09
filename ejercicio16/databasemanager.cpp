#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QCryptographicHash>
#include <QDebug>

DatabaseManager::DatabaseManager(const QString &path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    if (!db.open()) {
        qWarning() << "No se pudo abrir la base de datos:" << db.lastError();
    }
}

DatabaseManager::~DatabaseManager()
{
    if (db.isOpen()) {
        db.close();
    }
}

bool DatabaseManager::isOpen() const
{
    return db.isOpen();
}

bool DatabaseManager::validarUsuario(const QString &usuario, const QString &clave)
{
    QString hash = QString(QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Md5).toHex());

    QSqlQuery query;
    query.prepare("SELECT 1 FROM usuarios WHERE nombre = ? AND clave = ?");
    query.addBindValue(usuario);
    query.addBindValue(hash);

    return query.exec() && query.next();
}

QString DatabaseManager::obtenerUltimoUsuario()
{
    QSqlQuery query("SELECT valor FROM config WHERE clave = 'ultimo_usuario'");
    if (query.next()) {
        return query.value(0).toString();
    }
    return "";
}

void DatabaseManager::guardarUltimoUsuario(const QString &usuario)
{
    QSqlQuery query;
    query.prepare("INSERT OR REPLACE INTO config(clave, valor) VALUES('ultimo_usuario', ?)");
    query.addBindValue(usuario);
    query.exec();
}
