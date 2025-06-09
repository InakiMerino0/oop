#include "teclado.h"
#include <QDebug>

Teclado::Teclado(QWidget *parent)
    : Instrumento(parent), Electrico(), teclas(61)
{}

void Teclado::sonar() const
{
    qDebug() << "Teclado suena...";
}

void Teclado::verlo() const
{
    Instrumento::verlo();
    qDebug() << "Teclas:" << teclas;
    qDebug() << "Voltaje:" << voltaje;
}

int Teclado::getTeclas() const { return teclas; }
void Teclado::setTeclas(int value) { teclas = value; }
