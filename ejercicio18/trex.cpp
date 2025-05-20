#include "TRex.h"
#include <QPainter>
#include <QTimer>

static const int JUMP_HEIGHT = 80;
static const int CROUCH_HEIGHT = 20;
static const int WIDTH = 40;
static const int HEIGHT = 60;

TRex::TRex(QWidget *parent)
    : QWidget(parent),
    m_baseY(parent->height() - HEIGHT - 10),
    m_yPos(m_baseY),
    m_isJumping(false),
    m_isCrouching(false)
{
    setFixedSize(WIDTH, HEIGHT);
    move(50, m_yPos);
}

void TRex::paintEvent(QPaintEvent*) {
    QPainter p(this);
    p.setBrush(Qt::darkGray);
    p.drawRect(0, 0, width(), height());
}

QRect TRex::hitBox() const {
    return QRect(x(), y(), width(), height());
}

void TRex::jump() {
    if (m_isJumping) return;
    m_isJumping = true;
    m_yPos = m_baseY - JUMP_HEIGHT;
    move(x(), m_yPos);
    QTimer::singleShot(500, this, SLOT(endJump()));
}

void TRex::endJump() {
    m_yPos = m_baseY;
    move(x(), m_yPos);
    m_isJumping = false;
}

void TRex::crouch() {
    if (m_isCrouching) return;
    m_isCrouching = true;
    setFixedSize(WIDTH, CROUCH_HEIGHT);
    m_yPos = m_baseY + (HEIGHT - CROUCH_HEIGHT);
    move(x(), m_yPos);
    QTimer::singleShot(500, this, SLOT(endCrouch()));
}

void TRex::endCrouch() {
    setFixedSize(WIDTH, HEIGHT);
    m_yPos = m_baseY;
    move(x(), m_yPos);
    m_isCrouching = false;
}

void TRex::standUp() {
    if (m_isCrouching) endCrouch();
}
