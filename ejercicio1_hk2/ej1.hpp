#ifndef EJ1_HPP
#define EJ1_HPP

#include <iostream>
#include <iomanip>

using namespace std;

class Reloj {
private:
    int _hora;
    int _minutos;
    int _segundos;
    string _pmam;

public:
    // Constructor
    Reloj(int hora, int minutos, int segundos, string pmam);
    // Métodos
    int cambiar_24(int hora, string periodo);
    void print(int hora, int minutos, int segundos, string pmam);
    void print24(int hora, int minutos, int segundos);
    void menu(int hora, int minutos, int segundos, string periodo);
    void menu2(int hora, int minutos, int segundos, string periodo);
    int ingresar_horas();
    int ingresar_minutos();
    int ingresar_segundos();
    string ingresar_periodo();
};

#endif