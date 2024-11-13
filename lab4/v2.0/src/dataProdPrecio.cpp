#include "../include/dataProdPrecio.h"

DataProdPrecio::DataProdPrecio(string codigo, string nombre, int cantidad, float descuento, float subtotal) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->cantidad = cantidad;
    this->descuento = descuento;
    this->subtotal = subtotal;
}

string DataProdPrecio::getCodigo() {
    return codigo;
}

string DataProdPrecio::getNombre() {
    return nombre;
}

int DataProdPrecio::getCantidad() {
    return cantidad;
}

float DataProdPrecio::getDescuento() {
    return descuento;
}

float DataProdPrecio::getSubtotal() {
    return subtotal;
}