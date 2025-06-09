#include "bateria.h"
#include <QDebug>

Bateria::Bateria(QWidget *parent)
    : Instrumento(parent), tambores(5)
{}

void Bateria::sonar() const
{
    qDebug() << "Batería suena...";
}

void Bateria::verlo() const
{
    Instrumento::verlo();
    qDebug() << "Tambores:" << tambores;
}

int Bateria::getTambores() const { return tambores; }
void Bateria::setTambores(int value) { tambores = value; }
