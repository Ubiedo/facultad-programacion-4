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

Cliente* Compra::getCliente() {
    return cliente;
}

void Compra::agregarCP(CompraProducto* cp, string codigo) {
    productos[codigo] = cp;
}

DataCompraExp Compra::getDataCompraExp() {
    vector<DataProdExp> prods;
    map<string, CompraProducto*>::iterator itPrd;
    for (itPrd = productos.begin(); itPrd != productos.end(); ++itPrd) {
        DataProdExp dpe = itPrd->second->getDataProdExp();
        prods.push_back(dpe);
    }
    DataCompraExp dce = DataCompraExp(codigo, monto, fecha, prods);
    return dce;
}