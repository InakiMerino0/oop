#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QSqlDatabase>

class DatabaseManager
{
public:
    explicit DatabaseManager(const QString &path);
    ~DatabaseManager();

    bool isOpen() const;

    bool validarUsuario(const QString &usuario, const QString &clave);
    QString obtenerUltimoUsuario();
    void guardarUltimoUsuario(const QString &usuario);

private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
