#include "bienvenida.h"
#include <QVBoxLayout>

Bienvenida::Bienvenida(const QString& nombre, const QString& ultimo, QWidget *parent)
    : QWidget(parent)
{
    lblNombre = new QLabel(nombre);
    lblNombre->setStyleSheet("font-size: 24px; font-weight: bold;");

    lblIngreso = new QLabel("Último ingreso: " + ultimo);
    lblIngreso->setStyleSheet("font-size: 14px;");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lblNombre);
    layout->addWidget(lblIngreso);
    setLayout(layout);

    setWindowTitle("Bienvenido");
    resize(400, 200);
}
