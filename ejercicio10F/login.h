#ifndef LOGIN_H
#define LOGIN_H7

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>

class Login : public QWidget {
    Q_OBJECT

public:
    Login();
private:
    QLabel * lUsuario, * lClave;
    QLineEdit * leUsuario, * leClave;
    QPushButton * pbIngresar;
    QGridLayout * layout;

private slots: // Para validacion de usuarios
    void slot_validarUsuario();

};


#endif // LOGIN_H
