#include "ej4.cpp"


int main(){
    //creo una cuenta de ahorro y una cuenta corriente
    CajaAhorro caja_de_ahorro(500, "Nicolas Diez"); //inicializo la cuenta de ahorro con 500
    CuentaCte cuenta_corriente(&caja_de_ahorro);
    //retiro 100 y muestro la informacion de la caja de ahorro
    caja_de_ahorro.retirar(100);
    caja_de_ahorro.show_info();
    cout << endl;
    //muestro la informacion de la cuenta corriente, inicializada en 0, y le deposito 300
    cuenta_corriente.depositar(300);
    cuenta_corriente.show_info();
    cout << endl;
    //retiro 50 de la cuenta corriente y deposito 150 en la caja de ahorro
    cuenta_corriente.retirar(50);
    caja_de_ahorro.depositar(150);
    cout << endl;
    //muestro la informacion de ambas cuentas
    cuenta_corriente.show_info();
    caja_de_ahorro.show_info();
    cout << endl;
    //retiro 350 de la cuenta corriente, que no tiene suficiente dinero, y muestro la informacion de ambas cuentas
    //la cuenta corriente queda en 0 y se retira el resto de la caja de ahorro
    cuenta_corriente.retirar(350);
    cuenta_corriente.show_info();
    cout << endl;
    caja_de_ahorro.show_info(); // pido nuevamente para que me cobre los 20
    //pruebo retirar 1000, pero no hay esa suma en ambas cuentas
    cuenta_corriente.retirar(1000);
}