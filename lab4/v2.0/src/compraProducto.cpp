#include "../include/compraProducto.h"

CompraProducto::CompraProducto(int cantidadProducto, Compra* compra, Producto* producto) {
    this->cantidadProducto = cantidadProducto;
    this->compra = compra;
    this->producto = producto;
    this->estado = pendiente;
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

void CompraProducto::marcarComoEnviado() {
    this->estado = entregado;
}

DataProdExp CompraProducto::getDataProdExp() {
    DataProdExp dpe = DataProdExp(producto->getCodigo(), producto->getNombre(), producto->getVendedor()->getNickname(), producto->getDescripcion(), producto->getCategoria(), cantidadProducto, estado);
    return dpe;
}