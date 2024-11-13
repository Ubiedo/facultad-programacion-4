#include "../include/dtfecha.h"

//Ausencia de parámetros, se define dia = 1, mes = 1, anio = 0, default.
DTFecha::DTFecha(){
    Dia = 1;
    Mes = 1;
    Anio = 0;
}

//Se crea la fecha con los datos dia, mes, anio.
DTFecha::DTFecha(int dia, int mes, int anio){
    Dia = dia;
    Mes = mes;
    Anio = anio;
}

//Desctructor default.
DTFecha::~DTFecha(){
}

//Retorna dia.
int DTFecha::getDia(){
    return Dia;
}

//Retorna mes.
int DTFecha::getMes(){
    return Mes;
}

//Retorna anio.
int DTFecha::getAnio(){
    return Anio;
}

//Devuelve true si es mayor o igual.
bool operator>=(const DTFecha& f1, const DTFecha& f2){
    if ((f1.Anio > f2.Anio) || (f1.Anio == f2.Anio && f1.Mes > f2.Mes) || (f1.Anio == f2.Anio && f1.Mes == f2.Mes && f1.Dia >= f2.Dia))
    {
        return true;
    }
    return false;
}