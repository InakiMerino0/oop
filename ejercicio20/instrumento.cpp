#include "instrumento.h"
#include <QDebug>

Instrumento::Instrumento(QWidget *parent)
    : QWidget(parent), marca("Yamaha")
{}

Instrumento::~Instrumento() {}

void Instrumento::verlo() const
{
    qDebug() << "Marca:" << marca;
}
