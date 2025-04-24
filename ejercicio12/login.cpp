#include "ui_login.h"
#include "widget.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrlQuery>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login),
    netManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    connect( ui->pbIngresar, SIGNAL(pressed()), this, SLOT(slot_validarUsuario()));
    connect( netManager, &QNetworkAccessManager::finished, this, &Login::onClimaRespuesta);

    solicitarClima();
}

Login::~Login()
{
    delete ui;
}


void Login::slot_validarUsuario() {

    if (ui->leUsuario->text() == "admin" && ui->leClave->text() == "1234") {
        this->close();
    } else {
        ui->leClave->clear();
    }
}

void Login::solicitarClima() {
    // Construir URL:
    QUrl url("https://api.open-meteo.com/v1/forecast");
    QUrlQuery q;
    q.addQueryItem("latitude", "-31.4167");
    q.addQueryItem("longitude", "-64.1833");
    q.addQueryItem("current_weather", "true");
    url.setQuery(q);

    // Enviar GET:
    netManager->get(QNetworkRequest(url));
}

void Login::onClimaRespuesta(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        // Parsear JSON:
        const QByteArray data = reply->readAll();
        const QJsonDocument doc = QJsonDocument::fromJson(data);
        const QJsonObject root = doc.object();
        const QJsonObject cw = root.value("current_weather").toObject();
        double temp = cw.value("temperature").toDouble();

        // Poner en el QLabel (asume que existe ui->lblTemp):
        ui->lTemperatura->setText(QString::number(temp, 'f', 1) + " °C");
    } else {
        ui->lTemperatura->setText("Error al cargar clima");
    }
    reply->deleteLater();
}
