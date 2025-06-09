#ifndef BOTON_H
#define BOTON_H

#include <QWidget>
#include <QColor>

namespace Ui { class Boton; }

class Boton : public QWidget {
    Q_OBJECT

public:
    enum Color { Azul, Verde, Magenta };

    explicit Boton(QWidget *parent = nullptr);
    ~Boton();

    void colorear(Color c);

signals:
    void signal_clic();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::Boton *ui;
    QColor     m_color;
};

#endif // BOTON_H
