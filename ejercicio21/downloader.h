#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Downloader;
}
QT_END_NAMESPACE

class Downloader : public QWidget
{
    Q_OBJECT

public:
    Downloader(QWidget *parent = nullptr);
    ~Downloader();

private:
    Ui::Downloader *ui;
};
#endif // DOWNLOADER_H
