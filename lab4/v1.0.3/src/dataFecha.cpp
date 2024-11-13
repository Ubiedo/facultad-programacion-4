#include "../include/dataFecha.h"

DataFecha::DataFecha() {
    this->dia = 1;
    this->mes = 1;
    this->anio = 0;
}

DataFecha::DataFecha(int dia, int mes, int anio){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int DataFecha::getDia(){
    return this->dia;
}

int DataFecha::getMes(){
    return this->mes;
}

int DataFecha::getAnio(){
    return this->anio;
}

//Devuelve true si f1 es mayor o igual a f2
bool operator>=(const DataFecha& f1, const DataFecha& f2){
    if ((f1.anio > f2.anio) || (f1.anio == f2.anio && f1.mes > f2.mes) 
    || (f1.anio == f2.anio && f1.mes == f2.mes && f1.dia >= f2.dia))
        return true;
    else
        return false;
}