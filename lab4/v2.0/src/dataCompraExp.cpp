#include "../include/dataCompraExp.h"

DataCompraExp::DataCompraExp(string codigo, float monto, DataFecha fecha, vector<DataProdExp> productos) {
    this->codigo = codigo;
    this->monto = monto;
    this->fecha = fecha;
    this->productos = productos;
}

string DataCompraExp::getCodigo() {
    return codigo;
}

float DataCompraExp::getMonto() {
    return monto;
}

DataFecha DataCompraExp::getFecha() {
    return fecha;
}

vector<DataProdExp> DataCompraExp::getProductos() {
    return productos;
}