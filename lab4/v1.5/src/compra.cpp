#include "../include/compra.h"

Compra::Compra(string codigo, DataFecha fecha, float monto, Cliente* cliente) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->monto = monto;
    this->cliente = cliente;
}

Compra::~Compra() {
    map<string, CompraProducto*>::iterator itCProd;
    for (itCProd = productos.begin(); itCProd != productos.end(); ++itCProd)
        delete itCProd->second;
}

string Compra::getCodigo() {
    return codigo;
}

DataFecha Compra::getFecha() {
    return fecha;
}

float Compra::getMonto() {
    return monto;
}

void Compra::agregarCP(CompraProducto* cp, string codigo) {
    productos[codigo] = cp;
}