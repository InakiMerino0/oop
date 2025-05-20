#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QTimer>
#include <vector>
#include "TRex.h"
#include "Pajaro.h"
#include <QPaintEvent>    // para paintEvent
#include <QKeyEvent>      // para keyPressEvent

class GameWidget : public QWidget {
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);

protected:
    // Estas dos deben estar declaradas aquí para que el linker las encuentre:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void onMainTimer();
    void spawnPajaro();
    void gameOver();

private:
    TRex                 *m_trex;
    std::vector<QRect>    m_cactus;
    std::vector<Pajaro*>  m_pajaros;
    QTimer               *m_mainTimer;
    QTimer               *m_spawnTimer;
    int                    m_speedFactor;
    bool                   m_isGameOver;

    void resetGame();
};

#endif // GAMEWIDGET_H
