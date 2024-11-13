#include "../include/DataFecha.h"

DataFecha::DataFecha() {
    this->dia = 1;
    this->mes = 1;
    this->anio = 0;
}

DataFecha::DataFecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int DataFecha::getDia() {
    return this->dia;
}

int DataFecha::getMes() {
    return this->mes;
}

int DataFecha::getAnio() {
    return this->anio;
}

string DataFecha::toString() {
    string stringMes;
    switch (mes) {
        case 1:
            stringMes = "enero";
            break;
        case 2:
            stringMes = "febrero";
            break;
        case 3:
            stringMes = "marzo";
            break;
        case 4:
            stringMes = "abril";
            break;
        case 5:
            stringMes = "mayo";
            break;
        case 6:
            stringMes = "junio";
            break;
        case 7:
            stringMes = "julio";
            break;
        case 8:
            stringMes = "agosto";
            break;
        case 9:
            stringMes = "septiembre";
            break;
        case 10:
            stringMes = "octubre";
            break;
        case 11:
            stringMes = "noviembre";
            break;
        case 12:
            stringMes = "diciembre";
            break;
    }
    return to_string(dia) + " de " + stringMes + " de " + to_string(anio);
}

//Devuelve true si f1 es mayor o igual a f2
bool operator>=(const DataFecha& f1, const DataFecha& f2) {
    if ((f1.anio > f2.anio) || (f1.anio == f2.anio && f1.mes > f2.mes) 
    || (f1.anio == f2.anio && f1.mes == f2.mes && f1.dia >= f2.dia))
        return true;
    else
        return false;
}