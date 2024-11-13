#include "../include/dataProdConsulta.h"

DataProdConsulta::DataProdConsulta(string vendedor, string descripcion, Categoria categoria, int stock, float precio) {
    this->vendedor = vendedor;
    this->descripcion = descripcion;
    this->categoria = categoria;
    this->stock = stock;
    this->precio = precio;
}

string DataProdConsulta::getVendedor() {
    return this->vendedor;
}

string DataProdConsulta::getDescripcion() {
    return this->descripcion;
}

Categoria DataProdConsulta::getCategoria() {
    return this->categoria;
}

int DataProdConsulta::getStock() {
    return this->stock;
}

float DataProdConsulta::getPrecio() {
    return this->precio;
}