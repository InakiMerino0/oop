#include <iostream>
#include "cuentabancaria.h"

int main() {
    CuentaBancaria cuenta1(1000);
    CuentaBancaria cuenta2(750);

    cuenta1.depositar(500);
    cuenta2.depositar(1000);

    std::cout << "Cuenta 1: ";
    cuenta1.mostrar();
    std::cout << "Cuenta 2: ";
    cuenta2.mostrar();

    if (compararSaldo(cuenta1, cuenta2))
        std::cout << "Cuenta 1 tiene más saldo." << std::endl;
    else
        std::cout << "Cuenta 2 tiene más saldo o el mismo." << std::endl;

    return 0;
}
