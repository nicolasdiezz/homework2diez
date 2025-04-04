#include "ej3.cpp"

int main(){
    //creo numeros enteros, los sumo, resto y multiplico
    Entero numero(20);
    Entero numero2(10); //tener en cuenta que los numeros se sobreescriben
    numero.sumar(numero2); // 20 + 10 = 30
    //el resultado de la suma se guarda en el primer numero
    cout << numero.get_valor() << endl;  
    numero.restar(numero2); // 30 - 10 = 20
    //el resultado de la resta se guarda en el primer numero
    cout << numero.get_valor() << endl;
    numero.multiplicar(numero2); // 20 * 10 = 200
    cout << numero.get_valor() << endl;
    cout << endl;
    //creo numeros reales, los sumo, resto y multiplico
    Real numero3(2.5);
    Real numero4(1.5);
    numero3.sumar(numero4);
    cout << numero3.get_valor() << endl;
    numero3.restar(numero4);
    cout << numero3.get_valor() << endl;
    numero3.multiplicar(numero4);
    cout << numero3.get_valor() << endl;
    cout << endl;
    //creo numeros complejos, los sumo, resto y multiplico
    Complejo numero5(8,4);
    Complejo numero6(6,2);
    numero5.sumar(numero6);
    cout << numero5.get_valor_real() << " + " << numero5.get_valor_im() << " i" << endl;
    numero5.restar(numero6);
    cout << numero5.get_valor_real() << " + " << numero5.get_valor_im() << " i" << endl;
    numero5.multiplicar(numero6);
    cout << numero5.get_valor_real() << " + " << numero5.get_valor_im() << " i" << endl;

    return 0;
}