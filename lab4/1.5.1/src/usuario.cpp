#include "../include/usuario.h"
#include "iostream"

Usuario::Usuario() {}

Usuario::~Usuario() {}

string Usuario::getNickname() {
    return this->nickname;
}

string Usuario::getContrasena() {
    return this->contrasena;
}

DataFecha Usuario::getFechaNacimiento() {
    return this->fechaNacimiento;
}

void Usuario::setNickname(string nickname) {
    this->nickname = nickname;
}

void Usuario::setContrasena(string contrasena) {
    this->contrasena = contrasena;
}

void Usuario::setFechaNacimiento(DataFecha fechaNacimiento) {
    this->fechaNacimiento = fechaNacimiento;
}

void Usuario::agregarComentario(Comentario* cmt) {
    comentarios[cmt->getCodigo()] = cmt;
}

void Usuario::removerComentario(string codigo) {
    comentarios.erase(codigo);
}

bool Usuario::isEmptyComentarios() {
    return comentarios.empty();
}

Comentario* Usuario::findComentario(string codigo) {
    return comentarios[codigo];
}

vector<DataCmtBasica> Usuario::getComentarios() {
    vector<DataCmtBasica> res;
    map<string, Comentario*>::iterator itCmt;
    for (itCmt = comentarios.begin(); itCmt != comentarios.end(); ++itCmt) {
        res.push_back(itCmt->second->getDataCmtBasica());
    }
    return res;
}