#include "../include/vendedor.h"

Vendedor::Vendedor(DataVendedor dv) {
    this->nickname = dv.getNickname();
    this->contrasena = dv.getContrasena();
    this->fechaNacimiento = dv.getFechaNacimiento();
    this->nroRut = dv.getNroRut();
}

Vendedor::~Vendedor() {
    map<string, Comentario*>::iterator itCmt;
    for (itCmt = comentarios.begin(); itCmt != comentarios.end(); ++itCmt)
        delete itCmt->second;
}

string Vendedor::getNroRut() {
    return this->nroRut;
}

void Vendedor::setNroRut(string nroRut) {
    this->nroRut = nroRut;
}

string Vendedor::toString() {
    string res = "Nickname: " + this->nickname + "\n" 
    + "Fecha de nacimiento: " + this->fechaNacimiento.toString() + "\n" 
    + "Número de RUT: " + this->nroRut + "\n";
    return res;
}

//Requeridas por CtrlPromoProd

void Vendedor::agregarProducto(Producto* prod) {
    productos[prod->getCodigo()] = prod;
}