#include "../include/dataVendedor.h"

DataVendedor::DataVendedor(string nickname, string contrasena, DataFecha fechaNacimiento, string nroRut) {
    this->nickname = nickname;
    this->contrasena = contrasena;
    this->fechaNacimiento = fechaNacimiento;
    this->nroRut = nroRut;
}

string DataVendedor::getNroRut() {
    return this->nroRut;
}