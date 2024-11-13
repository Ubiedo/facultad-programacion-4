#include "../include/promocion.h"

Promocion::Promocion(Vendedor* vendedor, string nombre, string descripcion, float descuento, DataFecha vencimiento) {
    this->vendedor = vendedor;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->descuento = descuento;
    this->vencimiento = vencimiento;
}

Promocion::~Promocion() {
    map<string, PromoProducto*>::iterator itPP;
    for (itPP = productos.begin(); itPP != productos.end(); ++itPP)
        delete itPP->second;
}

string Promocion::getNombre() {
    return this->nombre;
}

string Promocion::getDescripcion() {
    return this->descripcion;
}

float Promocion::getDescuento() {
    return this->descuento;
}

DataFecha Promocion::getVencimiento() {
    return this->vencimiento;
}

Vendedor* Promocion::getVendedor() {
    return this->vendedor;
}

bool Promocion::esVigente(DataFecha fecha) {
    return (vencimiento >= fecha);
}

void Promocion::agregarPP(PromoProducto* pp, string codigoProducto) {
    productos[codigoProducto] = pp;
}

DataPromoConsulta Promocion::getDataPromoConsulta() {
    DataPromoConsulta res = DataPromoConsulta(nombre, descripcion, descuento, vencimiento);
    return res;
}

vector<DataProductosPromo> Promocion::infoProductos() {
    vector<DataProductosPromo> res;
    map<string, PromoProducto*>::iterator itPP;
    for (itPP = productos.begin(); itPP != productos.end(); ++itPP) {
        DataProductosPromo dpp = itPP->second->getDataProductosPromo();
        res.push_back(dpp);
    }
    return res;
}