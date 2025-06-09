#ifndef BATERIA_H
#define BATERIA_H

#include "instrumento.h"

class Bateria : public Instrumento
{
    Q_OBJECT
public:
    explicit Bateria(QWidget *parent = nullptr);
    void sonar() const override;
    void verlo() const override;

    int getTambores() const;
    void setTambores(int value);

private:
    int tambores = 5;
};

#endif // BATERIA_H
