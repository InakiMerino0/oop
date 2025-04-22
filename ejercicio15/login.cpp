#include "./login.h"
#include "./bienvenida.h"

#include <QtSql/QSqlQuery>
#include <QDateTime>
#include <QMessageBox>
#include <QtSql/QSqlError>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)

{
    ui->setupUi(this);
    conectarBase();

    connect(ui->pbIngresar, SIGNAL(pressed()), this, SLOT(slot_validarUsuario()));
}

Login::~Login()
{
    db.close();
    delete ui;
}

void Login::conectarBase() {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("usuariosdb");     // nombre de la base creada en MySQL
    db.setUserName("root");         // <-- tu usuario MySQL
    db.setPassword("admin");      // <-- tu contraseña MySQL

    if (!db.open()) {
        QMessageBox::critical(this, "Error", "No se pudo conectar a la base de datos MySQL:\n" + db.lastError().text());
    }
}

void Login::slot_validarUsuario()
{
    QString usuario = ui->leUsuario->text();
    QString clave = ui->leClave->text();

    QSqlQuery query;
    query.prepare("SELECT clave, ultimo_ingreso FROM usuarios WHERE nombre = ?");
    query.addBindValue(usuario);

    if (query.exec() && query.next()) {
        QString claveBD = query.value(0).toString();
        QString ultimoIngreso = query.value(1).toString();

        if (clave == claveBD) {
            // Actualizar último ingreso
            QString ahora = QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss");
            QSqlQuery update;
            update.prepare("UPDATE usuarios SET ultimo_ingreso = ? WHERE nombre = ?");
            update.addBindValue(ahora);
            update.addBindValue(usuario);
            update.exec();

            this->close();
            Bienvenida *ventana = new Bienvenida(usuario, ultimoIngreso);
            ventana->show();
        } else {
            QMessageBox::warning(this, "Error", "Contraseña incorrecta.");
            ui->leClave->clear();
        }
    } else {
        QMessageBox::warning(this, "Error", "Usuario no encontrado.");
        ui->leClave->clear();
    }
}
