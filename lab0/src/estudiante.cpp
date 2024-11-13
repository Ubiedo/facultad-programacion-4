#include "../include/estudiante.h"

//Se crea un estudiante con nombre, ci, email.
Estudiante::Estudiante(string nombre, int ci, string email){
    Nombre = nombre;
    CI = ci;
    Email = email;
}

//Retorna nombre.
string Estudiante::getNombre(){
    return Nombre;
}

//Retorna ci.
int Estudiante::getCI(){
    return CI;
}

//Retorna email.
string Estudiante::getEmail(){
    return Email;
}

//Modifica el email registrado.
void Estudiante::setEmail (string email) {
    this->Email = email; 
}

//Se imprime la información que guarda el estudiante con la fecha posterior al parámetro proporcionado.
vector<string> Estudiante::listarInfo(DTFecha Desde){
    vector<string> Obtenido; // aca se va a guardar los toString() de las informaciones
    // bucle for para recorrer toda la info guardada por el estudiante
    for (unsigned int i = 0; i < Guardado.size(); i++){
        // si es posterior o igual a la fecha que buscamos guardamos en Obtenido
        if (Guardado[i]->getFecha() >= Desde){
            Obtenido.push_back(Guardado[i]->toString());
        }
    }
    return Obtenido;
}

//El estudiante guarda otra información.
void Estudiante::addInfoGuardado(Informacion* informacion){
    Guardado.push_back(informacion);
}

//El estudiante guarda varias informaciones.
void Estudiante::addInfoGuardado(vector<Informacion*> informacion){
    for (unsigned int i = 0; i < informacion.size(); i++){
        Guardado.push_back(informacion[i]);
    }
}

//Se elimina información del estudiante con el identifiacdor proporcionado.
void Estudiante::removeInfoGuardado(int identificador){
    for (unsigned int i = 0; i < Guardado.size(); i++){
        if (Guardado[i]->getIdentificador() == identificador){
            Guardado.erase(Guardado.begin() + i);
            break;
        }
    }
}

//Retorna la información del estudiante.
string Estudiante::toString () {
    string retornar = "Estudiante: " + Nombre + ", " + to_string(getCI()) + ", " + Email;
    return retornar;
}

//Destructor por defecto
Estudiante::~Estudiante(){  
}