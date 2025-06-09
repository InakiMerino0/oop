#ifndef ELECTRICO_H
#define ELECTRICO_H

#include <QObject>

class Electrico
{
public:
    Electrico();
    virtual ~Electrico();

    int getVoltaje() const;
    void setVoltaje(int value);

protected:
    int voltaje = 220;
};

#endif // ELECTRICO_H
