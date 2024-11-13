#include "../include/compraProducto.h"

CompraProducto::CompraProducto(int cantidadProducto, Compra* compra, Producto* producto) {
    this->cantidadProducto = cantidadProducto;
    this->compra = compra;
    this->producto = producto;
}

int CompraProducto::getCantidadProducto() {
    return cantidadProducto;
}    
        
EstadoEnvio CompraProducto::getEstadoEnvio() {
    return estado;
}

Compra* CompraProducto::getCompra() {
    return compra;
}

Producto* CompraProducto::getProducto() {
    return producto;
}

void CompraProducto::setEnviado(){
    this->estado = entregado;
}