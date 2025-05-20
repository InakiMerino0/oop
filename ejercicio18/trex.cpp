#include "TRex.h"
#include <QPainter>

static const int WIDTH         = 40;
static const int HEIGHT        = 60;
static const int CROUCH_HEIGHT = 30;

TRex::TRex(QWidget *parent)
    : QWidget(parent),
    m_baseY(parent->height() - HEIGHT - 10),
    m_yPos(m_baseY),
    m_isJumping(false),
    m_isCrouching(false),
    m_jumpTimer(new QTimer(this)),
    m_velocity(0),
    m_crouchTimer(new QTimer(this))
{
    setFixedSize(WIDTH, HEIGHT);
    move(50, m_yPos);

    connect(m_jumpTimer, SIGNAL(timeout()), this, SLOT(updateJump()));
    connect(m_crouchTimer, SIGNAL(timeout()), this, SLOT(endCrouch()));
}

void TRex::paintEvent(QPaintEvent*) {
    QPainter p(this);
    p.setBrush(Qt::darkGray);
    p.drawRect(0,0,width(),height());
}

QRect TRex::hitBox() const {
    return QRect(x(), y(), width(), height());
}

void TRex::jump() {
    if (m_isJumping || m_isCrouching) return;
    m_isJumping = true;
    m_velocity = INIT_VELOCITY;
    m_jumpTimer->start(30);
}

void TRex::updateJump() {
    m_velocity += GRAVITY;
    m_yPos     += m_velocity;
    if (m_yPos >= m_baseY) {
        m_yPos = m_baseY;
        m_isJumping = false;
        m_jumpTimer->stop();
    }
    move(x(), m_yPos);
}

void TRex::crouch() {
    if (m_isJumping || m_isCrouching) return;
    m_isCrouching = true;
    setFixedSize(WIDTH, CROUCH_HEIGHT);
    m_yPos = m_baseY + (HEIGHT - CROUCH_HEIGHT);
    move(x(), m_yPos);
    m_crouchTimer->start(500);  // se mantiene agachado 500ms
}

void TRex::endCrouch() {
    m_crouchTimer->stop();
    setFixedSize(WIDTH, HEIGHT);
    m_yPos = m_baseY;
    move(x(), m_yPos);
    m_isCrouching = false;
}

void TRex::standUp() {
    if (m_isCrouching) endCrouch();
}
