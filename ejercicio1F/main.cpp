#include <iostream>
#include <vector>

using namespace std;

// Clase Poste
class Poste {
private:
    int altura;
    float diametro;

public:
    Poste(int alt, float dia) : altura(alt), diametro(dia) {}

    int getAltura() const {
        return altura;
    }

    float getDiametro() const {
        return diametro;
    }

    void mostrar() const {
        cout << "Altura: " << altura << " m, Diametro: " << diametro << " cm" << endl;
    }
};

void mostrarPostes(const vector<Poste>& postes) {
    for (const Poste& p : postes) {
        p.mostrar();
    }
}

// bubble sort para ordenar por altura
void ordenarPorAltura(vector<Poste>& postes) {
    int n = postes.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (postes[j].getAltura() > postes[j + 1].getAltura()) {
                swap(postes[j], postes[j + 1]);
            }
        }
    }
}

int main() {

    vector<Poste> postes;

    postes.push_back(Poste(10, 30.5));
    postes.push_back(Poste(7, 25.0));
    postes.push_back(Poste(12, 32.0));
    postes.push_back(Poste(9, 28.5));
    postes.push_back(Poste(5, 20.0));

    cout << "Postes sin ordenar:" << endl;
    mostrarPostes(postes);

    // Ordenar los postes por altura
    ordenarPorAltura(postes);

    cout << "Postes ordenados por altura:" << endl;
    mostrarPostes(postes);

    return 0;
}
