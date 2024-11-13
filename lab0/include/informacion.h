#ifndef INFORMACION
#define INFORMACION

#include "dtfecha.h"
#include "estudiante.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Estudiante;

class Informacion {
    private:
        int Identificador;
        DTFecha Fecha;
        vector<Estudiante*> GuardadoPor;
    public:
        int getIdentificador();
        void setIdentificador(int identificador);

        DTFecha getFecha();
        void setFecha(DTFecha fecha);

        // para manipular que estudiantes le guardaron
        void addGuardadoPorEstudiante(Estudiante* estudiante);
        void removeGuardadoPorEstudiante(int ci);
        vector<Estudiante*> getGuardadoPor();

        virtual string toString() = 0;
        virtual ~Informacion();
};

class PaginaWeb:public Informacion{
    private:
        string Titulo, Link, Text;
    public:
        PaginaWeb(int identificador, DTFecha fecha, string titulo, string link, string text);
        ~PaginaWeb();
        string getTitulo();
        string getLink();
        string getText();
        string toString();
};

class ChatGPT:public Informacion{
    private:
        string Pregunta, Respuesta;
    public:
        ChatGPT(int identificador, DTFecha fecha, string pregunta, string respuesta);
        ~ChatGPT();
    
        string getPregunta();
        string getRespuesta();
    
        string toString();
};

class Libro:public Informacion{
    private:
        string Titulo, Resumen;
        vector<string> Autores;
    public:
        Libro(int identificador, DTFecha fecha, string titulo, vector<string> autores, string resumen);
        ~Libro();
        string getTitulo();
        string getResumen();
        vector<string> getAutores();
        string toString();
};

#endif