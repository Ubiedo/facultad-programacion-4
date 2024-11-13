#include "../include/informacion.h"

// --------------------------------------- información ---------------------------------------

//Retorna identificador.
int Informacion::getIdentificador(){
    return Identificador;
}

//Se asigna identificador.
void Informacion::setIdentificador(int identificador){
    Identificador = identificador;
}

//Retorna fecha.
DTFecha Informacion::getFecha(){
    return Fecha;
}

//Se asigna fecha.
void Informacion::setFecha(DTFecha fecha){
    Fecha = fecha;
}

//La guardó un estudiante, mantenemos registro.
void Informacion::addGuardadoPorEstudiante(Estudiante* estudiante){
    GuardadoPor.push_back(estudiante);
}

//La eliminó un estudiante, eliminamos registro.
void Informacion::removeGuardadoPorEstudiante(int ci){
    for (unsigned int i = 0; i < GuardadoPor.size(); i++){
        if (GuardadoPor[i]->getCI() == ci){
            //delete GuardadoPor[i];
            //GuardadoPor[i] = NULL;
            GuardadoPor.erase(GuardadoPor.begin() + i);
            break;
        }
    }
}

//Retorna quiénes la guardaron.
vector<Estudiante*> Informacion::getGuardadoPor(){
    return GuardadoPor;
}

//Destructor por defecto
Informacion::~Informacion(){  
}

// --------------------------------------- página  web ---------------------------------------

//Se crea un registro.
PaginaWeb::PaginaWeb(int identificador, DTFecha fecha, string titulo, string link, string text){
    setIdentificador(identificador);
    setFecha(fecha);
    Titulo = titulo;
    Link = link;
    Text = text;
}

//Retorna titulo.
string PaginaWeb::getTitulo(){
    return Titulo;
}

//Retorna link.
string PaginaWeb::getLink(){
    return Link;
}

//Retorna text.
string PaginaWeb::getText(){
    return Text;
}

//Retorna la información del registro.
string PaginaWeb::toString(){
    return "PaginaWeb: " + to_string(getIdentificador()) + ", " + to_string(getFecha().getDia()) + "/" + to_string(getFecha().getMes()) + "/" + to_string(getFecha().getAnio()) + ", " + Titulo + ", " + Link + ", " + Text; 
}

//Destructor por defecto
PaginaWeb::~PaginaWeb(){  
}

// ---------------------------------------  chat  gpt  ---------------------------------------

//Se crea un registro.
ChatGPT::ChatGPT(int identificador, DTFecha fecha, string pregunta, string respuesta){
    setIdentificador(identificador);
    setFecha(fecha);
    Pregunta = pregunta;
    Respuesta = respuesta;
}

//Retorna pregunta.
string ChatGPT::getPregunta(){
    return Pregunta;
}

//Retorna respuesta.
string ChatGPT::getRespuesta(){
    return Respuesta;
}

//Retorna la información del registro.
string ChatGPT::toString(){
    return "chatGPT: " + to_string(getIdentificador()) + ", " + to_string(getFecha().getDia()) + "/" + to_string(getFecha().getMes()) + "/" + to_string(getFecha().getAnio()) + ", " + Pregunta + ", " + Respuesta; 
}

//Destructor por defecto
ChatGPT::~ChatGPT(){  
}

// ---------------------------------------    libro    ---------------------------------------

//Se crea un registro.
Libro::Libro(int identificador, DTFecha fecha, string titulo, vector<string> autores, string resumen){
    setIdentificador(identificador);
    setFecha(fecha);
    Titulo = titulo;
    Autores = autores;
    Resumen = resumen;
}

//Retorna titulo.
string Libro::getTitulo(){
    return Titulo;
}

//Retorna resumen.
string Libro::getResumen(){
    return Resumen;
}

//Retorna autores.
vector<string> Libro::getAutores(){
    return Autores;
}

//Retorna la información del registro.
string Libro::toString(){
    string retornar = "Libro: " + to_string(getIdentificador()) + ", " + to_string(getFecha().getDia()) + "/" + to_string(getFecha().getMes()) + "/" + to_string(getFecha().getAnio()) + ", " + Titulo + ", ";
    for (unsigned int i = 0; i < Autores.size(); i++)
    {
        retornar = retornar + Autores[i] + ", ";
    }
    retornar = retornar + Resumen;
    return retornar;
}

//Destructor por defecto
Libro::~Libro(){  
}