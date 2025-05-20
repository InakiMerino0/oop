#include "grafico.h"
#include "ui_grafico.h"

Grafico::Grafico(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Grafico)
{
    ui->setupUi(this);
}

Grafico::~Grafico()
{
    delete ui;
}
