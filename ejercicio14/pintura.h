#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QColor>

class Pintura : public QWidget {
    Q_OBJECT

public:
    Pintura(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    QVector<QVector<QPoint>> trazos;
    QVector<QColor> colores;
    QVector<int> grosores;

    QColor colorActual;
    int grosorActual;
    bool dibujando;
};

#endif // PINTURA_H
