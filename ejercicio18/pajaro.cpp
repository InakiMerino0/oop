#include "Pajaro.h"
#include <QPainter>

static const int WIDTH = 30;
static const int HEIGHT = 20;

Pajaro::Pajaro(int startY, int speed, QWidget *parent)
    : QWidget(parent),
    m_speed(speed)
{
    setFixedSize(WIDTH, HEIGHT);
    move(parent->width(), startY);
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    m_timer->start(30);
}

void Pajaro::paintEvent(QPaintEvent*) {
    QPainter p(this);
    p.setBrush(Qt::red);
    p.drawEllipse(0, 0, width(), height());
}

QRect Pajaro::hitBox() const {
    return QRect(x(), y(), width(), height());
}

void Pajaro::onTimeout() {
    move(x() - m_speed, y());
    if (x() + width() < 0) {
        m_timer->stop();
        deleteLater();
    }
}
