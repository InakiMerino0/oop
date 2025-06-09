#include "Boton.h"
#include "ui_Boton.h"
#include <QPainter>

Boton::Boton(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Boton),
    m_color(Qt::gray)
{
    ui->setupUi(this);
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
}

Boton::~Boton() {
    delete ui;
}

void Boton::colorear(Color c) {
    switch (c) {
    case Azul:    m_color = Qt::blue;    break;
    case Verde:   m_color = Qt::green;   break;
    case Magenta: m_color = Qt::magenta; break;
    }
    update();
}

void Boton::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.fillRect(rect(), m_color);
}

void Boton::mousePressEvent(QMouseEvent *) {
    emit signal_clic();
}
