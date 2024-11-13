#include "../include/cliente.h"

Cliente::Cliente(string nickname, string contrasena, DataFecha fechaNacimiento, string calle, string nroPuerta, string ciudad) {
    this->nickname = nickname;
    this->contrasena = contrasena;
    this->fechaNacimiento = fechaNacimiento;
    this->calle = calle;
    this->nroPuerta = nroPuerta;
    this->ciudad = ciudad;
}

Cliente::~Cliente() {
    map<string, Comentario*>::iterator itCmt;
    for (itCmt = comentarios.begin(); itCmt != comentarios.end(); ++itCmt)
        delete itCmt->second;

    map<string, Compra*>::iterator itCmp;
    for (itCmp = compras.begin(); itCmp != compras.end(); ++itCmp)
        delete itCmp->second;

    for (unsigned int i = 0; i < notificaciones.size(); i++) {
        delete notificaciones[i];
    }
}

string Cliente::getCalle() {
    return this->calle;
}

string Cliente::getNroPuerta() {
    return this->nroPuerta;
}

string Cliente::getCiudad() {
    return this->ciudad;
}

DataCliente Cliente::getDataCliente() {
    DataCliente dCl = DataCliente(nickname, fechaNacimiento, calle, nroPuerta, ciudad);
    return dCl;
}

void Cliente::notificar(DataNotificacion notificacion) {
    string codigo = nickname + "_ntf" + to_string(notificaciones.size() + 1);
    Notificacion* n = new Notificacion(codigo, notificacion.getNicknameVendedor(), notificacion.getNombrePromo(), notificacion.getProductosPromo());
    notificaciones.push_back(n);
}

bool Cliente::estaSuscrito(string vendedor) {
    return (suscripciones.count(vendedor) != 0);
}

void Cliente::suscribirse(Vendedor* v) {
    suscripciones[v->getNickname()] = v;
}

vector<DataNotificacion> Cliente::getNotificaciones() {
    vector<DataNotificacion> res;
    for (unsigned int i = 0; i < notificaciones.size(); i++) {
        res.push_back(notificaciones[i]->getDataNotificacion());
        delete notificaciones[i];
    }
    notificaciones.clear();
    return res;
}

vector<string> Cliente::getSuscripciones() {
    vector<string> res;
    map<string, Vendedor*>::iterator itCl;
    for (itCl = suscripciones.begin(); itCl != suscripciones.end(); ++itCl)
        res.push_back(itCl->first);
    return res;
}

void Cliente::desuscribirse(Vendedor* v) {
    suscripciones.erase(v->getNickname());
}

void Cliente::agregarCompra(Compra* cmp) {
    compras[cmp->getCodigo()] = cmp;
}

vector<DataCompraExp> Cliente::getCompraExpediente() {
    vector<DataCompraExp> res;
    map<string, Compra*>::iterator itCmp;
    for (itCmp = compras.begin(); itCmp != compras.end(); ++itCmp) {
        DataCompraExp dce = itCmp->second->getDataCompraExp();
        res.push_back(dce);
    }
    return res;
}