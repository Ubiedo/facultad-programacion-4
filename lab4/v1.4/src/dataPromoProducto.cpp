#include "../include/dataPromoProducto.h"

DataPromoProducto::DataPromoProducto(string codigoProducto, int minimoProducto) {
    this->codigoProducto = codigoProducto;
    this->minimoProducto = minimoProducto;
}

string DataPromoProducto::getCodigoProducto() {
    return this->codigoProducto;
}

int DataPromoProducto::getMinimoProducto() {
    return this->minimoProducto;
}