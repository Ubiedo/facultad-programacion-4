#include "../include/dataProducto.h"

DataProducto::DataProducto(string nombre, string descripcion, Categoria categoria, int stock, float precio) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->categoria = categoria;
    this->stock = stock;
    this->precio = precio;
}

string DataProducto::getNombre() {
    return this->nombre;
}

string DataProducto::getDescripcion() {
    return this->descripcion;
}

Categoria DataProducto::getCategoria() {
    return this->categoria;
}

int DataProducto::getStock() {
    return this->stock;
}

float DataProducto::getPrecio() {
    return this->precio;
}