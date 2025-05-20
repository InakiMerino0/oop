#ifndef TREX_H
#define TREX_H

#include <QWidget>
#include <QTimer>

class TRex : public QWidget {
    Q_OBJECT
public:
    explicit TRex(QWidget *parent = nullptr);
    QRect hitBox() const;

    // Salto
    void jump();
    // Agacharse y volver a altura normal
    void crouch();
    void standUp();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void updateJump();
    void endCrouch();

private:
    int     m_baseY;
    int     m_yPos;
    bool    m_isJumping;
    bool    m_isCrouching;

    // Para animar el salto
    QTimer *m_jumpTimer;
    int     m_velocity;
    static constexpr int GRAVITY        = 2;
    static constexpr int INIT_VELOCITY  = -20;

    // Para la duración del agacharse
    QTimer *m_crouchTimer;
};

#endif // TREX_H
