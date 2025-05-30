#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QShortcut>
#include <QKeySequence>
#include <QDebug>

// ---------- Login (definido primero) ----------
class Login : public QWidget {
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Login");

        QLabel *lblUsuario = new QLabel("Usuario:");
        QLabel *lblClave = new QLabel("Clave:");

        editUsuario = new QLineEdit;
        editClave = new QLineEdit;
        editClave->setEchoMode(QLineEdit::Password);

        QPushButton *btnIngresar = new QPushButton("Ingresar");

        connect(btnIngresar, SIGNAL(clicked()), this, SLOT(verificarLogin()));

        QShortcut *enterShortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
        connect(enterShortcut, SIGNAL(activated()), btnIngresar, SLOT(click()));

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(lblUsuario, 0, 0);
        layout->addWidget(editUsuario, 0, 1);
        layout->addWidget(lblClave, 1, 0);
        layout->addWidget(editClave, 1, 1);
        layout->addWidget(btnIngresar, 2, 0, 1, 2);

        setLayout(layout);
        resize(300, 120);
    }

public slots:
    void verificarLogin();

private:
    QLineEdit *editUsuario;
    QLineEdit *editClave;
};

// ---------- Formulario ----------
class Formulario : public QWidget {
    Q_OBJECT

public:
    Formulario(Login* loginRef, QWidget *parent = nullptr) : QWidget(parent), login(loginRef) {
        setWindowTitle("Formulario de Registro");

        QLabel *lblLegajo = new QLabel("Legajo:");
        QLabel *lblNombre = new QLabel("Nombre:");
        QLabel *lblApellido = new QLabel("Apellido:");

        editLegajo = new QLineEdit;
        editNombre = new QLineEdit;
        editApellido = new QLineEdit;

        QPushButton *btnGuardar = new QPushButton("Guardar");

        connect(btnGuardar, SIGNAL(clicked()), this, SLOT(guardarDatos()));

        QShortcut *enterShortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
        connect(enterShortcut, SIGNAL(activated()), btnGuardar, SLOT(click()));

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(lblLegajo, 0, 0);
        layout->addWidget(editLegajo, 0, 1);
        layout->addWidget(lblNombre, 1, 0);
        layout->addWidget(editNombre, 1, 1);
        layout->addWidget(lblApellido, 2, 0);
        layout->addWidget(editApellido, 2, 1);
        layout->addWidget(btnGuardar, 3, 0, 1, 2);

        setLayout(layout);
        resize(300, 150);
    }

public slots:
    void guardarDatos() {
        legajo = editLegajo->text();
        nombre = editNombre->text();
        apellido = editApellido->text();

        qDebug() << "Datos guardados:";
        qDebug() << "Legajo:" << legajo;
        qDebug() << "Nombre:" << nombre;
        qDebug() << "Apellido:" << apellido;

        this->close();
        login->show();
    }

private:
    QLineEdit *editLegajo;
    QLineEdit *editNombre;
    QLineEdit *editApellido;

    QString legajo;
    QString nombre;
    QString apellido;

    Login* login;
};

// ---------- Implementación del slot verificarLogin ----------
void Login::verificarLogin() {
    QString usuario = editUsuario->text();
    QString clave = editClave->text();

    if (usuario == "admin" && clave == "1111") {
        this->hide();
        Formulario *form = new Formulario(this);
        form->show();
    } else {
        editClave->clear();
    }
}

// ---------- main ----------
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Login login;
    login.show();

    return app.exec();
}

#include "main.moc"
