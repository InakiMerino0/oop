#ifndef BIENVENIDA_H
#define BIENVENIDA_H

#include <QWidget>
#include <QLabel>

class Bienvenida : public QWidget
{
    Q_OBJECT

public:
    Bienvenida(const QString& nombre, const QString& ultimo, QWidget *parent = nullptr);

private:
    QLabel *lblNombre;
    QLabel *lblIngreso;
};

#endif // BIENVENIDA_H
