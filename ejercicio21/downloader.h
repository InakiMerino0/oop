#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui { class Downloader; }
QT_END_NAMESPACE

class Downloader : public QWidget {
    Q_OBJECT

public:
    explicit Downloader(QWidget *parent = nullptr);
    ~Downloader();

private slots:
    void on_pushButtonCarpeta_clicked();
    void on_pushButtonDescargar_clicked();
    void onPaginaDescargada(QNetworkReply *reply);
    void onRecursoDescargado(QNetworkReply *reply);

private:
    Ui::Downloader *ui;
    QNetworkAccessManager *manager;
    QString carpetaDestino;

    void log(const QString &texto);
    void extraerYDescargarRecursos(const QString &html, const QUrl &baseUrl);
    void descargarRecurso(const QUrl &url);
};

#endif // DOWNLOADER_H
