#ifndef GUITARRA_H
#define GUITARRA_H

#include "instrumento.h"

class Guitarra : public Instrumento
{
    Q_OBJECT
public:
    explicit Guitarra(QWidget *parent = nullptr);
    void sonar() const override;
    void verlo() const override;

    int getCuerdas() const;
    void setCuerdas(int value);

private:
    int cuerdas = 6;
};

#endif // GUITARRA_H
