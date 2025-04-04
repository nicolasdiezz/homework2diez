#include "ej3.hpp"

//constructor
Entero :: Entero(int _valor){
    valor = _valor;
}

void Entero :: sumar(Numero& numero){
    valor = valor + dynamic_cast<Entero*>(&numero)->get_valor(); // Cast a Numero a Entero
}

void Entero :: restar(Numero& numero){
    valor = valor - dynamic_cast<Entero*>(&numero)->get_valor();
}

void Entero :: multiplicar(Numero& numero){
    valor = valor * dynamic_cast<Entero*>(&numero)->get_valor();
}

int Entero :: get_valor(){
    return valor;
}


//constructor
Real :: Real(float _valor){
    valor = _valor;
}

void Real :: sumar(Numero& numero){
    valor = valor + dynamic_cast<Real*>(&numero)->get_valor(); // Cast a Numero a Real
}

void Real :: restar(Numero& numero){
    valor = valor - dynamic_cast<Real*>(&numero)->get_valor();
}

void Real :: multiplicar(Numero& numero){
    valor = valor * dynamic_cast<Real*>(&numero)->get_valor();
}

float Real :: get_valor(){
    return valor;
}


//constructor
Complejo :: Complejo(float _real, float _imaginario){ //divido el numero complejo en su parte real e imaginaria
    real = _real;
    imaginario = _imaginario;
}

void Complejo :: sumar(Numero& numero){
    real = real + dynamic_cast<Complejo*>(&numero)->get_valor_real(); // Cast a Numero a Complejo
    imaginario = imaginario + dynamic_cast<Complejo*>(&numero)->get_valor_im(); //sumo real con real e imaginario con imaginario
}

void Complejo :: restar(Numero& numero){
    real = real - dynamic_cast<Complejo*>(&numero)->get_valor_real();
    imaginario = imaginario - dynamic_cast<Complejo*>(&numero)->get_valor_im();
}

void Complejo :: multiplicar(Numero& numero){
    int real_temp = real; //guardo el valor de la parte real
    real = (real * dynamic_cast<Complejo*>(&numero)->get_valor_real()) - (imaginario * dynamic_cast<Complejo*>(&numero)->get_valor_im());
    imaginario = (real_temp * dynamic_cast<Complejo*>(&numero)->get_valor_im()) + (imaginario * dynamic_cast<Complejo*>(&numero)->get_valor_real());
}//multiplico de la forma (a+bi)(c+di) = ac + adi + bci + bdi^2 = (ac-bd) + (ad+bc)i

float Complejo :: get_valor_real(){
    return real;
}

float Complejo :: get_valor_im(){
    return imaginario;
}
