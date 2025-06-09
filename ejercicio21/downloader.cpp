#include "downloader.h"
#include "ui_downloader.h"
#include <QFileDialog>
#include <QNetworkReply>
#include <QRegularExpression>
#include <QFileInfo>
#include <QFile>
#include <QDir>

Downloader::Downloader(QWidget *parent)
    : QWidget(parent), ui(new Ui::Downloader), manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPaginaDescargada(QNetworkReply*)));
}

Downloader::~Downloader() {
    delete ui;
}

void Downloader::on_pushButtonCarpeta_clicked() {
    carpetaDestino = QFileDialog::getExistingDirectory(this, "Elegir carpeta de destino");
    if (!carpetaDestino.isEmpty()) {
        ui->labelCarpeta->setText(carpetaDestino);
    }
}

void Downloader::on_pushButtonDescargar_clicked() {
    QUrl url(ui->lineEditUrl->text());
    if (!url.isValid() || url.scheme().isEmpty()) {
        log("URL inválida.");
        return;
    }
    log("Descargando HTML...");
    manager->get(QNetworkRequest(url));
}

void Downloader::onPaginaDescargada(QNetworkReply *reply) {
    if (reply->error()) {
        log("Error al descargar página: " + reply->errorString());
        reply->deleteLater();
        return;
    }

    QUrl baseUrl = reply->url();
    QString html = QString::fromUtf8(reply->readAll());
    log("HTML recibido. Buscando recursos...");

    reply->deleteLater();
    extraerYDescargarRecursos(html, baseUrl);
}

void Downloader::extraerYDescargarRecursos(const QString &html, const QUrl &baseUrl) {
    QRegularExpression regex(R"((?:href|src)=["']([^"']+)["'])");
    QRegularExpressionMatchIterator i = regex.globalMatch(html);

    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QUrl recursoUrl = baseUrl.resolved(QUrl(match.captured(1)));
        if (recursoUrl.isValid() && recursoUrl.scheme().startsWith("http")) {
            descargarRecurso(recursoUrl);
        }
    }
}

void Downloader::descargarRecurso(const QUrl &url) {
    QNetworkRequest request(url);
    QNetworkReply *reply = manager->get(request);

    connect(reply, SIGNAL(finished()), this, SLOT(onRecursoDescargado(QNetworkReply*)));
}

void Downloader::onRecursoDescargado(QNetworkReply *reply) {
    reply->deleteLater();

    if (reply->error()) {
        log("Error en recurso: " + reply->url().toString());
        return;
    }

    QString nombreArchivo = QFileInfo(reply->url().path()).fileName();
    if (nombreArchivo.isEmpty()) nombreArchivo = "archivo_descargado";

    QString rutaCompleta = carpetaDestino + "/" + nombreArchivo;
    QFile file(rutaCompleta);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(reply->readAll());
        file.close();
        log("Guardado: " + rutaCompleta);
    } else {
        log("Error al guardar: " + rutaCompleta);
    }
}

void Downloader::log(const QString &texto) {
    ui->textEditLog->append(texto);
}
