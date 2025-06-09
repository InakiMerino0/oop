#include "Ventana.h"
#include "ui_ventana.h"
#include "Boton.h"
#include <QPainter>
#include <QImage>
#include <QDebug>

Ventana::Ventana(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);

    // Conectar los 5 botones a un slot común
    connect(ui->boton1, SIGNAL(signal_clic()), this, SLOT(onBotonClicked()));
    connect(ui->boton2, SIGNAL(signal_clic()), this, SLOT(onBotonClicked()));
    connect(ui->boton3, SIGNAL(signal_clic()), this, SLOT(onBotonClicked()));
    connect(ui->boton4, SIGNAL(signal_clic()), this, SLOT(onBotonClicked()));
    connect(ui->boton5, SIGNAL(signal_clic()), this, SLOT(onBotonClicked()));

    // Asignar colores de ejemplo
    ui->boton1->colorear(Boton::Azul);
    ui->boton2->colorear(Boton::Verde);
    ui->boton3->colorear(Boton::Magenta);
    ui->boton4->colorear(Boton::Azul);
    ui->boton5->colorear(Boton::Verde);
}

Ventana::~Ventana() {
    delete ui;
}

void Ventana::paintEvent(QPaintEvent *) {
    QPainter p(this);

    // Dibujar imagen de fondo (asegurate de tenerla en tu resource o disco)
    QImage img(":/images/background.jpg");
    if (!img.isNull()) {
        p.drawImage(rect(), img);
    } else {
        // Si no, un degradado de respaldo
        QLinearGradient grad(0, 0, width(), height());
        grad.setColorAt(0.0, Qt::white);
        grad.setColorAt(1.0, Qt::cyan);
        p.fillRect(rect(), grad);
    }
}

void Ventana::onBotonClicked() {
    Boton *b = qobject_cast<Boton*>(sender());
    if (b) {
        qDebug() << "Click en" << b->objectName();
    }
}
