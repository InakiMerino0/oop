#ifndef LOGIN_H
#define LOGIN_H

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
    QNetworkAccesManager *netManagerBg;
    QPixmap pixmapBg;

    void descargarFondo();
    void aplicarFondo();

private slots:
    void slot_validarUsuario();
    void slot_fondoDescargado(QNetworkReply*);
};
#endif // LOGIN_H
