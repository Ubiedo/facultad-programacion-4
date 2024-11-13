#include "../include/dataCompra.h"

DataCompra::DataCompra(float monto, DataFecha fecha, vector<DataProdPrecio> productos) {
    this->monto = monto;
    this->fecha = fecha;
    this->productos = productos;
}

float DataCompra::getMonto() {
    return monto;
}

DataFecha DataCompra::getFecha() {
    return fecha;
}

vector<DataProdPrecio> DataCompra::getProductos() {
    return productos;
}