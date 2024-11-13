#include "../include/dataProdExp.h"

DataProdExp::DataProdExp(string codigo, string nombre, string vendedor, string descripcion, Categoria categoria, int cantidad, EstadoEnvio estado) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->vendedor = vendedor;
    this->descripcion = descripcion;
    this->categoria = categoria;
    this->cantidad = cantidad;
    this->estado = estado;
}

string DataProdExp::getCodigo() {
    return this->codigo;
}

string DataProdExp::getNombre() {
    return this->nombre;
}

string DataProdExp::getVendedor() {
    return this->vendedor;
}

string DataProdExp::getDescripcion() {
    return this->descripcion;
}

Categoria DataProdExp::getCategoria() {
    return this->categoria;
}

int DataProdExp::getCantidad() {
    return this->cantidad;
}

EstadoEnvio DataProdExp::getEstado() {
    return this->estado;
}