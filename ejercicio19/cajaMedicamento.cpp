#include "ui_cajaMedicamento.h"
#include "widget.h"

CajaMedicamento::CajaMedicamento(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CajaMedicamento)
{
    ui->setupUi(this);
}

CajaMedicamento::~CajaMedicamento()
{
    delete ui;
}
