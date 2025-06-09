#include "guitarra.h"
#include <QDebug>

Guitarra::Guitarra(QWidget *parent)
    : Instrumento(parent), cuerdas(6)
{}

void Guitarra::sonar() const
{
    qDebug() << "Guitarra suena...";
}

void Guitarra::verlo() const
{
    Instrumento::verlo();
    qDebug() << "Cuerdas:" << cuerdas;
}

int Guitarra::getCuerdas() const { return cuerdas; }
void Guitarra::setCuerdas(int value) { cuerdas = value; }
