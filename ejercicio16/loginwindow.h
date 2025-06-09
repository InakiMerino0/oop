#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "databasemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void intentarLogin();

private:
    Ui::LoginWindow *ui;
    DatabaseManager db;
};

#endif // LOGINWINDOW_H
