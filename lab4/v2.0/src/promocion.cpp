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

DataPromoConsulta Promocion::getDataPromoConsulta() {
    DataPromoConsulta res = DataPromoConsulta(nombre, descripcion, descuento, vencimiento);
    return res;
}

void Promocion::agregarPP(PromoProducto* pp, string codigoProducto) {
    productos[codigoProducto] = pp;
}

bool Promocion::esVigente(DataFecha fecha) {
    return (vencimiento >= fecha);
}

vector<DataProdPromo> Promocion::infoProductos() {
    vector<DataProdPromo> res;
    map<string, PromoProducto*>::iterator itPP;
    for (itPP = productos.begin(); itPP != productos.end(); ++itPP) {
        res.push_back(itPP->second->infoProducto());
    }
    return res;
}

bool Promocion::cumpleRequisitos(vector<DataProdCantidad> productosCantidad) {
    map<string, PromoProducto*>::iterator itPP = productos.begin();
    while ((itPP != productos.end()) && (itPP->second->cumpleRequisito(productosCantidad)))
        ++itPP;
    return (!(itPP != productos.end()));
}