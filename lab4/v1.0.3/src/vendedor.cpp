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

void Vendedor::setNroRut(string nroRut) {
    this->nroRut = nroRut;
}

string Vendedor::toString() {
    string res = "Nickname: " + this->nickname + "\n" 
    + "Fecha de nacimiento: " + to_string(this->fechaNacimiento.getDia()) + "/" 
    + to_string(this->fechaNacimiento.getMes()) + "/" + to_string(this->fechaNacimiento.getAnio()) 
    + "\n" + "Número de rut: " + this->nroRut + "\n";
    return res;
}

int Vendedor::generarId() {
    int id;
    if (productos.empty()) {
        id = 1;
    } else {
        map<int, Producto*>::iterator itProd;
        itProd = productos.end();
        id = itProd->first + 1;
    }
    return id;
}

void Vendedor::agregarProducto(Producto* prod) {
    productos[prod->getId()] = prod;
}

void Vendedor::notificar(){
    set<IObserver*>::iterator it;
    for (it = this->observers.begin(); it != this->observers.end(); ++it){
        (*it)->notificar();
    }
}