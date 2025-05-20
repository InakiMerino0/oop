#ifndef PAJARO_H
#define PAJARO_H

#include <QWidget>
#include <QTimer>

class Pajaro : public QWidget {
    Q_OBJECT
public:
    explicit Pajaro(int startY, int speed, QWidget *parent = nullptr);
    QRect hitBox() const;

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void onTimeout();

private:
    QTimer *m_timer;
    int     m_speed;
};

#endif // PAJARO_H
