#include "../include/dataProductosPromo.h"

DataProductosPromo::DataProductosPromo(string nombreProducto, string descripcionProducto, Categoria categoriaProducto, int stockProducto, float precioProducto, int minimoProducto) {
    this->nombreProducto = nombreProducto;
    this->descripcionProducto = descripcionProducto;
    this->categoriaProducto = categoriaProducto;
    this->stockProducto = stockProducto;
    this->precioProducto = precioProducto;
    this->minimoProducto = minimoProducto;
}

string DataProductosPromo::getNombreProducto() {
    return this->nombreProducto;
}

string DataProductosPromo::getDescripcionProducto() {
    return this->descripcionProducto;
}

Categoria DataProductosPromo::getCategoriaProducto() {
    return this->categoriaProducto;
}

int DataProductosPromo::getStockProducto() {
    return this->stockProducto;
}

float DataProductosPromo::getPrecioProducto() {
    return this->precioProducto;
}

int DataProductosPromo::getMinimoProducto() {
    return this->minimoProducto;
}