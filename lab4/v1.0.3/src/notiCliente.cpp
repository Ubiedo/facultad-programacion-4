#include "../include/notiCliente.h"

NotiCliente::NotiCliente(string nickVendedor, string nombPromo, string identificador, set<Producto*> productos) {
    this->nickVendedor = nickVendedor;
    this->nombPromo = nombPromo;
    this->identificador = identificador;
    this->productos = productos;
}

NotiCliente::~NotiCliente(){}

DataNotificacion NotiCliente::getDataNotificacion() {
    set<DataProducto> dProductos;
    set<Producto*>::iterator it;
    for (it = this->productos.begin(); it != this->productos.end(); ++it){
        dProductos.insert(DataProducto((*it)->getNombre(), (*it)->getDescripcion(), (*it)->getCategoria(), (*it)->getStock(), (*it)->getPrecio()));
    }
    return DataNotificacion(this->nickVendedor, this->nombPromo, dProductos);
}

string NotiCliente::getNickVendedor() {
    return this->nickVendedor;
}

string NotiCliente::getNombPromo() {
    return this->nombPromo;
}

string NotiCliente::getIdentificador() {
    this->identificador = identificador;
}

set<Producto*> NotiCliente::getProductos() {
    this->productos = productos;
}

set<DataProducto> NotiCliente::getDataProductos() {
    set<DataProducto> lista;
    if (!this->productos.empty()){
        set<Producto*>::iterator it; // iterador para set<int>
        for (it = this->productos.begin(); it != this->productos.end(); ++it){
            lista.insert(DataProducto((*it)->getNombre(), (*it)->getDescripcion(), (*it)->getCategoria(), (*it)->getStock(), (*it)->getPrecio()));
        }
    }
    return lista;
}

// void setProd(Producto prod){}