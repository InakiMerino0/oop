#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H

class CuentaBancaria {
private:
    int saldo;

public:
    CuentaBancaria(int saldoInicial);
    void depositar(int monto);
    void mostrar() const;

    friend bool compararSaldo(const CuentaBancaria& c1, const CuentaBancaria& c2);
};

#endif // CUENTABANCARIA_H
