#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QDoubleSpinBox>
#include <QPushButton>

class MainWidget : public QWidget {
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);

private slots:
    void slotAgregar();
    void slotSumar();
    void slotComparar();

private:
    void refrescarLista();

    QDoubleSpinBox *spinDosis;
    QPushButton    *btnAgregar;
    QListWidget    *listCajas;
    QPushButton    *btnSumar;
    QPushButton    *btnComparar;
};

#endif // MAINWIDGET_H
