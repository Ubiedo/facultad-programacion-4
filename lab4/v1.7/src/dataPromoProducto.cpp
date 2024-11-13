#include "../include/dataPromoProducto.h"

DataPromoProducto::DataPromoProducto(string codigoProducto, int cantidadProducto) {
    this->codigoProducto = codigoProducto;
    this->cantidadProducto = cantidadProducto;
}

string DataPromoProducto::getCodigoProducto() {
    return this->codigoProducto;
}

int DataPromoProducto::getCantidadProducto() {
    return this->cantidadProducto;
}