#include "ej1.cpp"

int main() {
    int horas = 0;
    int minutos = 0;
    int segundos = 0;
    string periodo = "am";

    Reloj reloj(horas, minutos, segundos, periodo);
    reloj.menu(horas, minutos, segundos, periodo);

    return 0;
}