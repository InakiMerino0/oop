#include "electrico.h"
#include <QDebug>

Electrico::Electrico() : voltaje(220) {}

Electrico::~Electrico()
{
    qDebug() << "Desenchufado";
}

int Electrico::getVoltaje() const { return voltaje; }
void Electrico::setVoltaje(int value) { voltaje = value; }
