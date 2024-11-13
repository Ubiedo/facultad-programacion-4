#include "../include/dataProdBasica.h"

DataProdBasica::DataProdBasica(string codigo, string nombre) {
    this->codigo = codigo;
    this->nombre = nombre;
}

string DataProdBasica::getCodigo() {
    return this->codigo;
}

string DataProdBasica::getNombre() {
    return this->nombre;
}