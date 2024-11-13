#ifndef ESTUDIANTE
#define ESTUDIANTE

#include "dtfecha.h"
#include "informacion.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Informacion;

class Estudiante{
    private:
        string Nombre, Email;
        int CI;
        vector<Informacion*> Guardado;
    public:
        Estudiante(string nombre, int ci, string email);
        ~Estudiante();
        
        string getNombre();
        int getCI();
        string getEmail();
        
        void setEmail(string);

        // para manipular info guardada por estudiante
        void addInfoGuardado(Informacion* informacion);
        void addInfoGuardado(vector<Informacion*> informacion);
        void removeInfoGuardado(int identificador);

        vector<string> listarInfo(DTFecha Desde);

        string toString();
};

#endif