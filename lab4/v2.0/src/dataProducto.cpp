#include "../include/dataProducto.h"

DataProducto::DataProducto(string codigo, string nombre, string descripcion, Categoria categoria, int stock, float precio) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->categoria = categoria;
    this->stock = stock;
    this->precio = precio;
}

string DataProducto::getCodigo() {
    return codigo;
}

string DataProducto::getNombre() {
    return nombre;
}

string DataProducto::getDescripcion() {
    return descripcion;
}

Categoria DataProducto::getCategoria() {
    return categoria;
}

int DataProducto::getStock() {
    return stock;
}

float DataProducto::getPrecio() {
    return precio;
}