#include "ej2.cpp"

int main(){
    string nombre;
    string nombre2;
    // Creo variables para almacenar la informacion de los estudiantes
    int legajo;
    float promedio;
    // Creo estudiantes
    Estudiante estudiante1("Nicolas Diez", 1010);
    Estudiante estudiante2("Joaquin Casas", 2030);
    Estudiante estudiante3("Lucas Gonzalez", 3040);
    Estudiante estudiante4("Chiqui Tapia", 7766);
    // Creo cursos y le agrego estudiantes
    Curso curso_quimica("quimica");
    curso_quimica.nuevo_estudiante(estudiante1, 9);
    curso_quimica.nuevo_estudiante(estudiante2, 6.5);
    curso_quimica.nuevo_estudiante(estudiante3, 4);
    Curso curso_matematica("matematica");
    curso_matematica.nuevo_estudiante(estudiante2, 4);
    curso_matematica.nuevo_estudiante(estudiante1, 6.5);
    curso_matematica.nuevo_estudiante(estudiante4, 8);
    curso_matematica.nuevo_estudiante(estudiante3, 10);
    // imprimo la informacion de un estudiante
    nombre = estudiante1.get_nombre();
    legajo = estudiante1.get_legajo();
    promedio = estudiante1.get_promedio();
    curso_quimica.curso_completo();
    cout << "nombre: " << nombre << ", legajo: " << legajo << ", promedio: " << promedio << endl;
    // imprimo la informacion de un curso
    nombre2 = estudiante2.get_nombre();
    cout << nombre2;
    curso_quimica.buscar_estudiante(estudiante2.get_legajo());
    cout << endl;
    curso_quimica.print_ordenados_alf();
    cout << endl;
    //creo una copia del curso quimica y le agrego un estudiante
    Curso curso_copia_quimica(curso_quimica);
    curso_copia_quimica.nuevo_estudiante(estudiante4, 10);
    // imprimo la informacion de la copia del curso quimica
    curso_copia_quimica.print_ordenados_alf();

    return 0;
}