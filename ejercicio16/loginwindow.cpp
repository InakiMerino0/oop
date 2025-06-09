#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
    , db("usuarios.db") // Asegurate de tener la BD en el mismo directorio
{
    ui->setupUi(this);

    ui->lEstado->setText("Ingrese sus credenciales");

    // Cargar último usuario logueado
    QString ultimo = db.obtenerUltimoUsuario();
    if (!ultimo.isEmpty()) {
        ui->leUsuario->setText(ultimo);
    }

    // Conectar el botón a la función de login
    connect(ui->pbIngresar, &QPushButton::clicked, this, &LoginWindow::intentarLogin);
}

void LoginWindow::intentarLogin()
{
    QString usuario = ui->leUsuario->text().trimmed();
    QString clave = ui->leClave->text();

    if (usuario.isEmpty() || clave.isEmpty()) {
        ui->lEstado->setText("Debe completar todos los campos.");
        return;
    }

    if (!db.isOpen()) {
        ui->lEstado->setText("Error de conexión a la base de datos.");
        return;
    }

    if (db.validarUsuario(usuario, clave)) {
        ui->lEstado->setText("Login exitoso.");
        db.guardarUltimoUsuario(usuario);
        // Aquí podrías cerrar o abrir una nueva ventana si querés
    } else {
        ui->lEstado->setText("Usuario o clave incorrecta.");
    }
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
