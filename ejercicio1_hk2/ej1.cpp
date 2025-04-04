#include "ej1.hpp"

//constructor
Reloj :: Reloj(int hora, int minutos, int segundos, string pmam){
    _hora = hora;
    _minutos = minutos;
    _segundos = segundos;
    _pmam = pmam;
}
//funcion que cambia el formato de 12 a 24 horas
int Reloj :: cambiar_24(int hora, string periodo) {
    if (periodo == "pm") return hora + 12;
    return hora;
}
//funcion que imprime la hora en formato 12 horas
void Reloj :: print(int _hora, int _minutos, int _segundos, string _pmam){
    cout << setfill('0') << setw(2) << _hora <<"h" << setfill('0') << setw(2) << _minutos <<"m" << setfill('0') << setw(2) << _segundos <<"s " << _pmam << endl;
}
//funcion que imprime la hora en formato 24 horas
void Reloj :: print24(int _horas, int _minutos, int _segundos){
    cout << setfill('0') << setw(2) << _horas <<"h" << setfill('0') << setw(2) << _minutos <<"m" << setfill('0') << setw(2) << _segundos <<"s " << endl;
}
//primero menu iterativo
void Reloj :: menu(int _horas, int _minutos, int _segundos, string _periodo){
    int num1;

    cout << "|| PRIMER MENU ||" << endl;
    cout << "USTED DESEA: " << endl;
    cout << "ingresar unicamente horas (1): " << endl;
    cout << "ingresar unicamente horas y minutos (2): " << endl;
    cout << "ingresar horas, minutos y segundos (3): " << endl;
    cout << "ingresar horas, minutos, segundos y periodo (4): " << endl;
    cout << " " << endl;
    cin >> num1;

    switch (num1){
        case 1: _horas = ingresar_horas(); //caso ingresar solo horas
        break;
        case 2: { 
            _horas = ingresar_horas(); //caso ingresar horas y minutos
            _minutos = ingresar_minutos();
            break;
        }
        case 3: {
            _horas = ingresar_horas(); //caso ingresar horas, minutos y segundos
            _minutos = ingresar_minutos();
            _segundos = ingresar_segundos();
            break;
        }
        case 4: {
            _horas = ingresar_horas(); 
            _minutos = ingresar_minutos(); //caso ingresar horas, minutos, segundos y periodo
            _segundos = ingresar_segundos(); 
            _periodo = ingresar_periodo();
        break;
        }
    }
    menu2(_horas, _minutos, _segundos, _periodo); //llamo al segundo menu
}
//segundo menu iterativo
void Reloj :: menu2(int _horas, int _minutos, int _segundos, string _periodo){
    int num2;

    cout << "|| SEGUNDO MENU ||" << endl;
    cout << "USTED DESEA: " << endl;
    cout << "cambiar hora (0): " << endl;
    cout << "cambiar minutos (1): " << endl;
    cout << "cambiar segundos (2): " << endl;
    cout << "cambiar periodo (3): " << endl;
    cout << "leer hora (4): " << endl;
    cout << "leer minutos (5): " << endl;
    cout << "leer segundos (6): " << endl;
    cout << "leer periodo (7): " << endl;
    cout << "leer todo (8): " << endl;
    cout << "leer todo en formato 24hs (9): " << endl;
    cout << "salir (10): " << endl;
    cout << " " << endl;
    cin >> num2 ;
    
    switch (num2){
        case 0: {
            _horas = ingresar_horas(); //cambiar hora
            menu2(_horas, _minutos, _segundos, _periodo);
            break;
        }
        case 1: {
            _minutos = ingresar_minutos(); //cambiar minutos
            menu2(_horas, _minutos, _segundos, _periodo);
            break;
        }
        case 2: {
            _segundos = ingresar_segundos(); //cambiar segundos
            menu2(_horas, _minutos, _segundos, _periodo);
            break;
        }
        case 3: {
            _periodo = ingresar_periodo(); //cambiar periodo
            menu2(_horas, _minutos, _segundos, _periodo);
            break;
        }
        case 4: {
            cout << _horas << "h" << endl; //leer hora
            menu2(_horas, _minutos, _segundos, _periodo);
            break;
        }
        case 5: {
            cout << _minutos << "m" << endl; //leer minutos
            menu2(_horas, _minutos, _segundos, _periodo);
            break;
        }
        case 6: {
            cout << _segundos << "s" << endl; //leer segundos
            menu2(_horas, _minutos, _segundos, _periodo);
            break;
        }
        case 7: {
            cout << _periodo << endl; //leer periodo
            menu2(_horas, _minutos, _segundos, _periodo);
            break;
        }
        case 8: {
            print(_horas, _minutos, _segundos, _periodo); //leer todo en formato 12hs
            menu2(_horas, _minutos, _segundos, _periodo);
            break;
        }
        case 9: { 
            print24(cambiar_24(_horas, _periodo), _minutos, _segundos); //leer todo en formato 24hs
            menu2(_horas, _minutos, _segundos, _periodo);
            break;
        }
        case 10: {
            break; //salir
        }
    } //luego de realizar cada cambio, vuelvo a llamar al menu2, excepto si elijo salir
}
//funcion para ingresar hora
int Reloj :: ingresar_horas(){
    int horas;
    cout << "Ingrese la hora (1-11): ";
    cin >> horas;
    while (horas < 1 || horas > 11) {
        cout << "ERROR: hora fuera de rango, ingrese un valor entre 1 y 11: ";
        cin >> horas;
    }
    return horas;
}
//funcion para ingresar minutos
int Reloj :: ingresar_minutos(){
    int minutos;
    cout << "Ingrese los minutos (0-59): ";
    cin >> minutos;
    while (minutos < 0 || minutos >= 60) {
        cout << "ERROR: minutos fuera de rango, ingrese un valor entre 0 y 59: ";
        cin >> minutos;
    }
    return minutos;
}
//funcion para ingresar segundos
int Reloj :: ingresar_segundos(){
    int segundos;
    cout << "Ingrese los segundos (0-59): ";
    cin >> segundos;
    while (segundos < 0 || segundos >= 60) {
        cout << "ERROR: segundos fuera de rango, Ingrese un valor entre 0 y 59: ";
        cin >> segundos;
    }
    return segundos;
}
//funcion para ingresar periodo
string Reloj :: ingresar_periodo(){
    string periodo;
    cout << "Ingrese el periodo ('am' / 'pm'): ";
    cin >> periodo;
    while (periodo != "am" && periodo != "pm") {
        cout << "ERROR: periodo inválido. Ingrese 'am' / 'pm': ";
        cin >> periodo;
    }
    return periodo;
}
