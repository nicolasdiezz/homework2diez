#ifndef EJ4_HPP
#define EJ4_HPP

#include <iostream>
using namespace std;

class Banco {
    protected:
        double balance;
        string titular;
    public:
        //constructor
        Banco(double _balance, string _titular);
        //metodos
        void depositar(float dinero);
        virtual void retirar(float dinero) = 0;
        virtual void show_info() = 0;

};

class CajaAhorro : public Banco {
    private:
    int contador = 0;
    public: 
        //constructor
        CajaAhorro(double _balance, string _titular);
        //metodos
        void retirar(float dinero) override;
        void show_info() override;
        friend class CuentaCte;
};

class CuentaCte : public Banco {
    private:
        CajaAhorro* caja_ahorro;
    public:
        //constructor
        CuentaCte(CajaAhorro* caja_ahorro);
        //metodos
        void retirar(float dinero) override;
        void show_info() override;
};


#endif