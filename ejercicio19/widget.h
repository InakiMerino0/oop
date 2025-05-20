#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class CajaMedicamento;
}
QT_END_NAMESPACE

class CajaMedicamento : public QWidget
{
    Q_OBJECT

public:
    CajaMedicamento(QWidget *parent = nullptr);
    ~CajaMedicamento();

private:
    Ui::CajaMedicamento *ui;
};
#endif // WIDGET_H
