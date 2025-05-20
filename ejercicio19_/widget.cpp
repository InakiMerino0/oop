#include "widget.h"
#include "AdminDBMedicamentos.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    // Conectar BD
    AdminDBMedicamentos::instancia()->conectar();

    // Widgets
    spinDosis    = new QDoubleSpinBox;
    spinDosis->setRange(0.0, 1000.0);
    btnAgregar   = new QPushButton("Agregar");
    listCajas    = new QListWidget;
    btnSumar     = new QPushButton("Sumar");
    btnComparar  = new QPushButton("Comparar");

    // Layouts
    QHBoxLayout *h1 = new QHBoxLayout;
    h1->addWidget(spinDosis);
    h1->addWidget(btnAgregar);

    QHBoxLayout *h2 = new QHBoxLayout;
    h2->addWidget(btnSumar);
    h2->addWidget(btnComparar);

    QVBoxLayout *main = new QVBoxLayout(this);
    main->addLayout(h1);
    main->addWidget(listCajas);
    main->addLayout(h2);

    // Conexiones
    connect(btnAgregar, SIGNAL(clicked()), this, SLOT(slotAgregar()));
    connect(btnSumar,   SIGNAL(clicked()), this, SLOT(slotSumar()));
    connect(btnComparar,SIGNAL(clicked()), this, SLOT(slotComparar()));

    // Inicializar lista
    refrescarLista();
}

void MainWidget::refrescarLista() {
    listCajas->clear();
    QList<CajaMedicamento> todas = AdminDBMedicamentos::instancia()->obtenerTodas();
    foreach (const CajaMedicamento &c, todas) {
        QListWidgetItem *it = new QListWidgetItem(c.toString());
        it->setData(Qt::UserRole, c.id());
        listCajas->addItem(it);
    }
}

void MainWidget::slotAgregar() {
    float dosis = spinDosis->value();
    if (!AdminDBMedicamentos::instancia()->insertarCaja(dosis)) {
        QMessageBox::warning(this, "Límite Excedido",
                             "No podés superar las 1000 dosis en total.");
    }
    refrescarLista();
}

void MainWidget::slotSumar() {
    QList<QListWidgetItem*> sel = listCajas->selectedItems();
    if (sel.count() != 2) return;

    int id1 = sel[0]->data(Qt::UserRole).toInt();
    int id2 = sel[1]->data(Qt::UserRole).toInt();
    QList<CajaMedicamento> todas = AdminDBMedicamentos::instancia()->obtenerTodas();
    CajaMedicamento c1, c2;
    foreach (const CajaMedicamento &c, todas) {
        if (c.id() == id1) c1 = c;
        if (c.id() == id2) c2 = c;
    }
    CajaMedicamento suma = c1 + c2;
    if (!AdminDBMedicamentos::instancia()->insertarCaja(suma.dosis())) {
        QMessageBox::warning(this, "Límite Excedido",
                             "La suma supera las 1000 dosis.");
    }
    refrescarLista();
}

void MainWidget::slotComparar() {
    QList<QListWidgetItem*> sel = listCajas->selectedItems();
    if (sel.count() != 2) return;

    int id1 = sel[0]->data(Qt::UserRole).toInt();
    int id2 = sel[1]->data(Qt::UserRole).toInt();
    QList<CajaMedicamento> todas = AdminDBMedicamentos::instancia()->obtenerTodas();
    CajaMedicamento c1, c2;
    foreach (const CajaMedicamento &c, todas) {
        if (c.id() == id1) c1 = c;
        if (c.id() == id2) c2 = c;
    }
    qDebug() << "Son iguales?" << (c1 == c2);
}
