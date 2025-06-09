#ifndef TECLADO_H
#define TECLADO_H

#include "instrumento.h"
#include "electrico.h"

class Teclado : public Instrumento, public Electrico
{
    Q_OBJECT
public:
    explicit Teclado(QWidget *parent = nullptr);
    void sonar() const override;
    void verlo() const override;

    int getTeclas() const;
    void setTeclas(int value);

private:
    int teclas = 61;
};

#endif // TECLADO_H
