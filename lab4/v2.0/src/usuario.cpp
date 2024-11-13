#include "../include/usuario.h"

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
    if (comentarios.count(codigo) != 0)
        return comentarios[codigo];
    else
        return NULL;
}

vector<DataComentario> Usuario::getComentarios() {
    vector<DataComentario> res;
    map<string, Comentario*>::iterator itCmt;
    for (itCmt = comentarios.begin(); itCmt != comentarios.end(); ++itCmt) {
        res.push_back(itCmt->second->getDataComentario());
    }
    return res;
}