#include "../include/dataProdCompra.h"

DataProdCompra::DataProdCompra(string codigo, string nombre, int stock) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->stock = stock;
}

string DataProdCompra::getCodigo() {
    return this->codigo;
}

string DataProdCompra::getNombre() {
    return this->nombre;
}

int DataProdCompra::getStock() {
    return this->stock;
}