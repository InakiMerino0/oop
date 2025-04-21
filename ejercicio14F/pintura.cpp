#include "pintura.h"
#include <QMouseEvent>
#include <QPainter>
#include <QWheelEvent>
#include <QKeyEvent>

Pintura::Pintura(QWidget *parent) : QWidget(parent), colorActual(Qt::black), grosorActual(2), dibujando(false) {
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);
}

void Pintura::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        trazos.append(QVector<QPoint>());
        colores.append(colorActual);
        grosores.append(grosorActual);
        trazos.last().append(event->pos());
        dibujando = true;
    }
}

void Pintura::mouseMoveEvent(QMouseEvent *event) {
    if (dibujando && (event->buttons() & Qt::LeftButton)) {
        trazos.last().append(event->pos());
        update();
    }
}

void Pintura::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    for (int i = 0; i < trazos.size(); ++i) {
        painter.setPen(QPen(colores[i], grosores[i], Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        for (int j = 1; j < trazos[i].size(); ++j) {
            painter.drawLine(trazos[i][j - 1], trazos[i][j]);
        }
    }
}

void Pintura::wheelEvent(QWheelEvent *event) {
    if (event->angleDelta().y() > 0 && grosorActual < 50) {
        grosorActual++;
    } else if (event->angleDelta().y() < 0 && grosorActual > 1) {
        grosorActual--;
    }
}

void Pintura::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_R) {
        colorActual = Qt::red;
    } else if (event->key() == Qt::Key_G) {
        colorActual = Qt::green;
    } else if (event->key() == Qt::Key_B) {
        colorActual = Qt::blue;
    } else if (event->key() == Qt::Key_Escape) {
        trazos.clear();
        colores.clear();
        grosores.clear();
        update();
    }
}
