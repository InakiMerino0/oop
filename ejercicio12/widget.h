#ifndef WIDGET_H
#define WIDGET_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::Login *ui;
    QNetworkAccessManager *netManager;

private slots:
    void slot_validarUsuario();
    void solicitarClima();
    void onClimaRespuesta(QNetworkReply *reply);
};
#endif // WIDGET_H
