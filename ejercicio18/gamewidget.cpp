#include "GameWidget.h"
#include <QPainter>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QMessageBox>

static const int CACTUS_WIDTH  = 20;
static const int CACTUS_HEIGHT = 40;
static const int GROUND_Y      = 300;
static const int BASE_SPEED    = 5;

GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent),
    m_speedFactor(1),
    m_isGameOver(false)
{
    setFixedSize(600, 350);
    // TRex
    m_trex = new TRex(this);

    // Main timer: mueve cactus y detecta colisiones
    m_mainTimer = new QTimer(this);
    connect(m_mainTimer, SIGNAL(timeout()), this, SLOT(onMainTimer()));
    m_mainTimer->start(30);

    // Spawn pájaros cada 5s
    m_spawnTimer = new QTimer(this);
    connect(m_spawnTimer, SIGNAL(timeout()), this, SLOT(spawnPajaro()));
    m_spawnTimer->start(5000);
}

void GameWidget::paintEvent(QPaintEvent*) {
    QPainter p(this);
    // suelo
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::green);
    p.drawRect(0, GROUND_Y + CACTUS_HEIGHT, width(), height() - GROUND_Y);

    // cactus
    p.setBrush(Qt::darkGreen);
    for (auto &r : m_cactus) {
        p.drawRect(r);
    }
    // TRex y pájaros se pintan en sus propios widgets
}

void GameWidget::keyPressEvent(QKeyEvent *e) {
    if (m_isGameOver && e->key() == Qt::Key_R) {
        resetGame();
        return;
    }
    if (m_isGameOver) return;

    switch (e->key()) {
    case Qt::Key_Space:  m_trex->jump();     break;
    case Qt::Key_Down:   m_trex->crouch();   break;
    case Qt::Key_Right:  m_speedFactor++;    break;
    case Qt::Key_Left:   m_speedFactor = qMax(1, m_speedFactor - 1); break;
    default: break;
    }
}

void GameWidget::onMainTimer() {
    if (m_isGameOver) return;

    // Mover cactus
    for (auto &r : m_cactus) {
        r.translate(-BASE_SPEED * m_speedFactor, 0);
    }
    // Eliminar fuera de pantalla
    while (!m_cactus.empty() && m_cactus.front().right() < 0)
        m_cactus.erase(m_cactus.begin());

    // Generar nuevo cactus si hace falta
    if (m_cactus.empty() || m_cactus.back().x() < width() - 200) {
        m_cactus.push_back(QRect(width(), GROUND_Y, CACTUS_WIDTH, CACTUS_HEIGHT));
    }

    // Chequear colisión con cactus
    QRect trexBox = m_trex->hitBox();
    for (auto &r : m_cactus) {
        if (r.intersects(trexBox)) {
            gameOver();
            return;
        }
    }
    // Chequear colisión con pájaros
    for (auto *b : m_pajaros) {
        if (b->hitBox().intersects(trexBox)) {
            gameOver();
            return;
        }
    }

    update();
}

void GameWidget::spawnPajaro() {
    if (m_isGameOver) return;

    // Tres alturas posibles
    int altos[3] = { GROUND_Y - 60, GROUND_Y - 100, GROUND_Y - 140 };
    int idx = QRandomGenerator::global()->bounded(3);
    Pajaro *p = new Pajaro(altos[idx], BASE_SPEED * m_speedFactor, this);
    m_pajaros.push_back(p);
}

void GameWidget::gameOver() {
    m_isGameOver = true;
    m_mainTimer->stop();
    m_spawnTimer->stop();
    QMessageBox::information(this, "Game Over", "¡Perdiste! Presioná R para reiniciar.");
}

void GameWidget::resetGame() {
    // Borrar cactus
    m_cactus.clear();
    // Borrar pájaros
    for (auto *b : m_pajaros) {
        b->deleteLater();
    }
    m_pajaros.clear();

    m_speedFactor = 1;
    m_isGameOver  = false;
    m_mainTimer->start(30);
    m_spawnTimer->start(5000);
    update();
}
