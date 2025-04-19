#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QTimer>
#include <QScreen>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QLabel label;

    // Ruta a la imagen JPG (reemplazá esto con la tuya)
    QString imagePath = "C:/Users/Usuario-/OneDrive/Imágenes/design.png";

    QPixmap pixmap(imagePath);
    if (pixmap.isNull()) {
        qWarning("No se pudo cargar la imagen");
        return -1;
    }

    // Escalar sin deformar, manteniendo la relación de aspecto
    QSize screenSize = QGuiApplication::primaryScreen()->availableGeometry().size();
    QPixmap scaledPixmap = pixmap.scaled(screenSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    label.setPixmap(scaledPixmap);
    label.setAlignment(Qt::AlignCenter);
    label.setWindowFlags(Qt::Window); // Para que sea una ventana independiente
    label.showMaximized();

    // Cerrar después de 3 segundos
    QTimer::singleShot(3000, &app, &QApplication::quit);

    return app.exec();
}
