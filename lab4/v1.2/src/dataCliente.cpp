#include "../include/dataCliente.h"

DataCliente::DataCliente(string nickname, string contrasena, DataFecha fechaNacimiento, string calle, int nroPuerta, string ciudad) {
    this->nickname = nickname;
    this->contrasena = contrasena;
    this->fechaNacimiento = fechaNacimiento;
    this->calle = calle;
    this->nroPuerta = nroPuerta;
    this->ciudad = ciudad;
}

string DataCliente::getCalle() {
    return this->calle;
}

int DataCliente::getNroPuerta() {
    return this->nroPuerta;
}

string DataCliente::getCiudad() {
    return this->ciudad;
}