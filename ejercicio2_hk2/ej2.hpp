#ifndef EJ2_HPP
#define EJ2_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Estudiante{
    private:
        string nombre;
        int legajo;
        vector<pair<string, float>> lista_curso;
    
    public:
        // Constructor
        Estudiante(string _nombre, int _legajo);
        // metodos
        void agregar_curso(string curso, float nota);
        string get_nombre();
        int get_legajo();
        float get_promedio();
        bool operator<(Estudiante& estudiante) const;

};

class Curso{
    private:
        string materia;
        vector<Estudiante> estudiantes_curso;
    
    public:
        // Constructor
        Curso(string _materia);
        // Constructor de copia
        Curso(Curso* curso);
        // metodos
        void nuevo_estudiante(Estudiante& estudiante, float nota);
        void buscar_estudiante(int legajo);
        void curso_completo();
        void print_ordenados_alf();
};


#endif