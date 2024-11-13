#include "../include/dataPromocion.h"

DataPromocion::DataPromocion(string nickname, vector<DataPromoProducto> productosPromocion, string nombre, string descripcion, float descuento, DataFecha vencimiento) {
    this->nickname = nickname;
    this->productosPromocion = productosPromocion;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->descuento = descuento;
    this->vencimiento = vencimiento;
}

string DataPromocion::getNickname() {
    return nickname;
}

vector<DataPromoProducto> DataPromocion::getProductosPromocion() {
    return productosPromocion;
}

string DataPromocion::getNombre() {
    return nombre;
}

string DataPromocion::getDescripcion() {
    return descripcion;
}

float DataPromocion::getDescuento() {
    return descuento;
}

DataFecha DataPromocion::getVencimiento() {
    return vencimiento;
}