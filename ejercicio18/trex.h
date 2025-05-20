#ifndef TREX_H
#define TREX_H

#include <QWidget>
#include <QTimer>

class TRex : public QWidget {
    Q_OBJECT
public:
    explicit TRex(QWidget *parent = nullptr);

    // Llamados desde GameWidget:
    void jump();
    void crouch();
    void standUp();

    QRect hitBox() const;

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void endJump();
    void endCrouch();

private:
    int     m_baseY;
    int     m_yPos;
    bool    m_isJumping;
    bool    m_isCrouching;
};

#endif // TREX_H
