#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Clase Archivo
class Archivo {
private:
    string nombre;
    int tamanoKB;
    char* contenido;

public:
    // Constructor
    Archivo(const string& nombreArchivo, int tamKB) {
        nombre = nombreArchivo;
        tamanoKB = tamKB;
        contenido = new char[tamanoKB * 1024]; // Reservamos memoria simulando el contenido
    }

    // Destructor
    ~Archivo() {
        delete[] contenido;
    }

    // Método para mostrar información básica
    void mostrar() const {
        cout << "Archivo: " << nombre << " - " << tamanoKB << " KB" << endl;
    }

    // Método para obtener el tamaño en bytes
    int obtenerTamanoBytes() const {
        return tamanoKB * 1024;
    }
};

int main() {
    vector<Archivo*> archivos;

    const int tamanoPorArchivoKB = 1024; // 1 MB por archivo
    const int maxRAM = 200 * 1024 * 1024; // 200 MB en bytes
    int memoriaUsada = 0;
    int contador = 0;

    while (memoriaUsada + (tamanoPorArchivoKB * 1024) <= maxRAM) {
        string nombre = "archivo_" + to_string(contador);
        Archivo* nuevo = new Archivo(nombre, tamanoPorArchivoKB);
        archivos.push_back(nuevo);
        memoriaUsada += tamanoPorArchivoKB * 1024;
        contador++;
    }

    cout << "Cantidad de objetos 'Archivo' creados antes de alcanzar 200 MB de RAM: " << contador << endl;

    // Liberar memoria
    for (Archivo* a : archivos) {
        delete a;
    }

    return 0;
}
