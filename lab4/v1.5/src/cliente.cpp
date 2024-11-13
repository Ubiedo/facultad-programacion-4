#include "../include/cliente.h"
#include "iostream"

Cliente::Cliente(DataCliente dc) {
    this->nickname = dc.getNickname();
    this->contrasena = dc.getContrasena();
    this->fechaNacimiento = dc.getFechaNacimiento();
    this->calle = dc.getCalle();
    this->nroPuerta = dc.getNroPuerta();
    this->ciudad = dc.getCiudad();
}

Cliente::~Cliente() {
    map<string, Comentario*>::iterator itCmt;
    for (itCmt = comentarios.begin(); itCmt != comentarios.end(); ++itCmt)
        delete itCmt->second;

    map<string, Compra*>::iterator itCmp;
    for (itCmp = compras.begin(); itCmp != compras.end(); ++itCmp)
        delete itCmp->second;
}

string Cliente::getCalle() {
    return this->calle;
}

int Cliente::getNroPuerta() {
    return this->nroPuerta;
}

string Cliente::getCiudad() {
    return this->ciudad;
}

string Cliente::toString() {
    string res = "Nickname: " + this->nickname + "\n" 
    + "Fecha de nacimiento: " + this->fechaNacimiento.toString() + "\n" 
    + "Calle: " + this->calle + "\n" + "Número de puerta: " + to_string(this->nroPuerta) + "\n" 
    + "Ciudad: " + this->ciudad + "\n";
    return res; 
}

void Cliente::notificar(string notificacion) {
    notificaciones.push_back(notificacion);
}

bool Cliente::estaSuscrito(string vendedor) {
    return (suscripciones.count(vendedor) != 0);
}

void Cliente::suscribirse(Vendedor* v) {
    suscripciones[v->getNickname()] = v;
}

vector<string> Cliente::getNotificaciones() {
    vector<string> res = notificaciones;
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