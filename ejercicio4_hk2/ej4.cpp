#include "ej4.hpp"

//constructor
Banco :: Banco(double _balance, string _titular){
    balance = _balance;
    titular = _titular;
}

void Banco :: depositar(float dinero){
    if(dinero < 0) cout << "no se puede ingresar dinero negativo" << endl;
    else {
        balance += dinero;
        cout << "se ha depositado $" << dinero << " en la cuenta" << endl;
    }
}

//constructor
CajaAhorro :: CajaAhorro(double _balance, string _titular) : Banco( _balance, _titular){}


void CajaAhorro :: retirar(float dinero){
    if(dinero > balance) cout << "Usted no tiene esa suma en su caja de ahorro" << endl;
    if(dinero < 0) cout << "no se puede retirar dinero en cantidades negativas" << endl;
    else {
        balance -= dinero;
        cout << "se ha retirado $" << dinero << " de la caja de ahorro" << endl;
    }
}

void CajaAhorro :: show_info(){
    contador++;
    if(contador == 3){ //cuento las veces que se pide la info
        if(balance >= 20) {
            balance -= 20;
            cout << "le hemos cobrado $20 por pedir mas de 2 veces la informacion caja de ahorro" << endl;
        }
        else cout << "le queremos cobrar $20 por pedir mas de 2 veces la informacion de la cuenta, pero usted no posee dinero para pagar esta suma" << endl;
        contador = 0;
    }
    cout << "tipo de cuenta: Caja de ahorro " << endl;
    cout << "balance de la cuenta: $" << balance << endl;
    cout << "titular: " << titular << endl; 
}


//constructor
CuentaCte :: CuentaCte(CajaAhorro* caja) : Banco(0, caja->titular), caja_ahorro(caja){
}


void CuentaCte :: retirar(float dinero){
    if(dinero < 0) cout << "no se puede retirar dinero en cantidades negativas" << endl;
    else if(balance >= dinero) { //si tengo suficiente dinero en la cuenta corriente, retiro solo de ahi
        balance -= dinero;
        cout << "se ha retirado $" << dinero << " de la cuenta corriente" << endl;
    }
    else {
        if(caja_ahorro->balance > dinero-balance) { //si no tengo suficiente dinero en la cuenta corriente, dejo la cuenta corriente en 0 y retiro el resto de la caja de ahorro
            cout << "se ha retirado $" << balance << " de la cuenta corriente" << endl;
            caja_ahorro->retirar(dinero-balance);
            balance = 0;
        }
        else cout << "no tienes $" << dinero << " para retirar" << endl; //en caso de que no tenga suficiente dinero en la cuenta corriente ni en la caja de ahorro
    }
}

void CuentaCte :: show_info(){
    cout << "tipo de cuenta: Cuenta Corriente " << endl;
    cout << "balance de la cuenta: $" << balance << endl;
    cout << "titular: " << titular << endl; 
}