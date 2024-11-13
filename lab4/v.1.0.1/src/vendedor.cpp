#include "../include/vendedor.h"

Vendedor::Vendedor(DataVendedor dv) {
    this->nickname = dv.getNickname();
    this->contrasena = dv.getContrasena();
    this->fechaNacimiento = dv.getFechaNacimiento();
    this->nroRut = dv.getNroRut();
}

string Vendedor::getNroRut() {
    return this->nroRut;
}

string Vendedor::toString() {
    string res = "Nickname: " + this->nickname + "\n" 
    + "Fecha de nacimiento: " + to_string(this->fechaNacimiento.getDia()) + "/" 
    + to_string(this->fechaNacimiento.getMes()) + "/" + to_string(this->fechaNacimiento.getAnio()) 
    + "\n" + "Número de rut: " + this->nroRut + "\n";
    return res;
}

void Vendedor::setNroRut(string nroRut) {
    this->nroRut = nroRut;
}