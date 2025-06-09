#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <QWidget>
#include <QString>

class Instrumento : public QWidget
{
    Q_OBJECT
public:
    explicit Instrumento(QWidget *parent = nullptr);
    virtual ~Instrumento();

    virtual void sonar() const = 0;
    virtual void verlo() const;

protected:
    QString marca = "Yamaha";
};

#endif // INSTRUMENTO_H
