#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDateTime>
#include "bienvenida.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::Login *ui;
    QSqlDatabase db;
    void conectarBase();

private slots:
    void slot_validarUsuario();
};
#endif // LOGIN_H
