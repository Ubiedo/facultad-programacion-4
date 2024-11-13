#include "../include/dataCompra.h"

DataCompra::DataCompra(float monto, DataFecha fecha, vector<string> infoProductos) {
    this->monto = monto;
    this->fecha = fecha;
    this->infoProductos = infoProductos;
}

float DataCompra::getMonto() {
    return monto;
}

DataFecha DataCompra::getFecha() {
    return fecha;
}

vector<string> DataCompra::getInfoProductos() {
    return infoProductos;
}