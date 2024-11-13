#include "../include/dataPromoConsulta.h"

DataPromoConsulta::DataPromoConsulta(string nombre, string descripcion, float descuento, DataFecha vencimiento) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->descuento = descuento;
    this->vencimiento = vencimiento;
}

string DataPromoConsulta::getNombre() {
    return this->nombre;
}

string DataPromoConsulta::getDescripcion() {
    return this->descripcion;
}

float DataPromoConsulta::getDescuento() {
    return this->descuento;
}

DataFecha DataPromoConsulta::getVencimiento() {
    return this->vencimiento;
}