#include "../include/dataProdCantidad.h"

DataProdCantidad::DataProdCantidad(string codigoProducto, int cantidadProducto) {
    this->codigoProducto = codigoProducto;
    this->cantidadProducto = cantidadProducto;
}

string DataProdCantidad::getCodigoProducto() {
    return this->codigoProducto;
}

int DataProdCantidad::getCantidadProducto() {
    return this->cantidadProducto;
}