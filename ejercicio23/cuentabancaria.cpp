#include "cuentabancaria.h"
#include <iostream>

CuentaBancaria::CuentaBancaria(int saldoInicial) : saldo(saldoInicial) {}

void CuentaBancaria::depositar(int monto) {
    saldo += monto;
}

void CuentaBancaria::mostrar() const {
    std::cout << "Saldo: " << saldo << std::endl;
}

bool compararSaldo(const CuentaBancaria& c1, const CuentaBancaria& c2) {
    return c1.saldo > c2.saldo;
}
