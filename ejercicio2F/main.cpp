#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    vector<string> expresiones;

    expresiones.push_back("Mal Ahi");
    expresiones.push_back("Cual hay");
    expresiones.push_back("Ya fue");
    expresiones.push_back("Pan Comido");
    expresiones.push_back("Tal cual");

    int n = expresiones.size();

    // Bubble sort ignorando espacios
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            string a = expresiones[j];
            string b = expresiones[j + 1];

            // Comparación ignorando espacios
            string aComp = "", bComp = "";

            for (char c : a) {
                if (c == ' ') continue;
                aComp += c;
            }

            for (char c : b) {
                if (c == ' ') continue;
                bComp += c;
            }

            if (aComp > bComp) {
                swap(expresiones[j], expresiones[j + 1]);
            }
        }
    }

    cout << "Expresiones ordenadas: " << endl;
    for (const string& s : expresiones) {
        cout << s << endl;
    }

    return 0;
}
