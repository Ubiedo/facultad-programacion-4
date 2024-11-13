#include "../include/dataProdPromo.h"

DataProdPromo::DataProdPromo(string nombre, string descripcion, Categoria categoria, int stock, float precio, int minimo) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->categoria = categoria;
    this->stock = stock;
    this->precio = precio;
    this->minimo = minimo;
}

string DataProdPromo::getNombre() {
    return this->nombre;
}

string DataProdPromo::getDescripcion() {
    return this->descripcion;
}

Categoria DataProdPromo::getCategoria() {
    return this->categoria;
}

int DataProdPromo::getStock() {
    return this->stock;
}

float DataProdPromo::getPrecio() {
    return this->precio;
}

int DataProdPromo::getMinimo() {
    return this->minimo;
}