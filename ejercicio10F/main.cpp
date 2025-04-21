#include <QApplication> // Al ser parte de la biblioteca se incluye con <>
#include "login.h" // cuando es codigo propio se incluye con "" (solo por materia de orden, se puede incluir de cualquiera de las dos formas)

int main (int argc, char **argv) {
    QApplication a ( argc, argv  );

    Login login;
    login.show();

    return a.exec();
}
