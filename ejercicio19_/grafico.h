#ifndef GRAFICO_H
#define GRAFICO_H

#include <QWidget>

namespace Ui {
class Grafico;
}

class Grafico : public QWidget
{
    Q_OBJECT

public:
    explicit Grafico(QWidget *parent = nullptr);
    ~Grafico();

private:
    Ui::Grafico *ui;
};

#endif // GRAFICO_H
