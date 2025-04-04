#include "ej2.hpp"

//constructor
Estudiante :: Estudiante(string _nombre, int _legajo){
    nombre = _nombre;
    legajo = _legajo;
}

void Estudiante :: agregar_curso(string curso, float nota){
    lista_curso.push_back(make_pair(curso, nota)); // Agrego el curso y la nota a la lista de cursos
}

string Estudiante :: get_nombre(){
    return nombre;
}

int  Estudiante :: get_legajo(){
    return legajo;
}

float Estudiante :: get_promedio(){
    float suma = 0;
    for(int i = 0; i < lista_curso.size(); i++){ // Recorro la lista de cursos
        suma += lista_curso[i].second; //agarro el segundo elemento de cada par (la nota)
    }
    return suma / lista_curso.size(); // Devuelvo el promedio de las notas
}

bool Estudiante :: operator<(Estudiante& estudiante) const {
    if(nombre < estudiante.get_nombre()) return true; 
    else return false;
}



ostream& operator<<(ostream& os, Estudiante estudiante){
os << estudiante.get_nombre() << endl;
return os;
}


//constructor
Curso :: Curso(string _materia){
    materia = _materia;
}

Curso :: Curso(Curso* curso){
    materia = curso->materia + "_copia"; // Copia el nombre de la materia
    estudiantes_curso = curso->estudiantes_curso; // Copia la lista de estudiantes
}

/* Para hacer una copia del curso, utilizo shallow copy, ya que quiero que la copia 
apunte a todos los estudiantes que tiene el curso que voy a copiar. De esta forma uso punteros
sin necesidad de duplicar la cantidad de nombres (ya que son las mismas personas)*/

void Curso :: nuevo_estudiante(Estudiante& estudiante, float nota){
    estudiantes_curso.push_back(estudiante); // Agrego el estudiante a la lista de estudiantes del curso
    estudiante.agregar_curso(materia, nota); // Agrego el curso y la nota al estudiante
}

void Curso :: buscar_estudiante(int legajo){
    int x = 0;
    for(int i = 0; i < estudiantes_curso.size(); i++){ // Recorro la lista de estudiantes
        if (legajo == estudiantes_curso[i].get_legajo()) { // Busco el legajo
            cout << " se encuentra en este curso" << endl;
            x++;
        }
    }
    if(x==0) cout << "el estudiante no se encuentra en el curso" << endl;
}

void Curso :: curso_completo(){
    if(estudiantes_curso.size() == 20) cout << "el curso esta completo" << endl;
    else cout << "el curso no esta completo todavia" << endl;
}

void Curso :: print_ordenados_alf(){
    sort(estudiantes_curso.begin(), estudiantes_curso.end()); // Ordeno la lista de estudiantes por nombre
    for(int i = 0; i < estudiantes_curso.size(); i++){
        cout << estudiantes_curso[i];
    }
}


