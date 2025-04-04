#ifndef EJ3_HPP
#define EJ3_HPP

#include <iostream>

using namespace std;

class Numero{

    public:
        //metodos virtuales puros
        virtual void sumar(Numero& numero) = 0;
        virtual void restar(Numero& numero) = 0;
        virtual void multiplicar(Numero& numero) = 0;

};

class Entero : public Numero{
    private:
        int valor;

    public:
        //constructor
        Entero(int _valor);
        //metodos
        void sumar(Numero& numero) override; //override para poder sobreescribir el metodo
        void restar(Numero& numero) override;
        void multiplicar(Numero& numero) override;
        int get_valor();

};

class Real : public Numero{
    private:
        float valor;

    public:
        //constructor
        Real(float _valor);
        //metodos
        void sumar(Numero& numero) override;
        void restar(Numero& numero) override;
        void multiplicar(Numero& numero) override;
        float get_valor();
};

class Complejo : public Numero{
    private:
        float real;
        float imaginario;
    
    public:
        //constructor
        Complejo(float _real, float _imaginario);
        //metodos
        void sumar(Numero& numero) override;
        void restar(Numero& numero) override;
        void multiplicar(Numero& numero) override;
        float get_valor_real();
        float get_valor_im();
};


#endif