#include "../include/dataVendedor.h"

DataVendedor::DataVendedor(string nickname, DataFecha fechaNacimiento, string nroRut) {
    this->nickname = nickname;
    this->fechaNacimiento = fechaNacimiento;
    this->nroRut = nroRut;
}

string DataVendedor::getNroRut() {
    return this->nroRut;
}