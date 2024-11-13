#include "../include/dataComentario.h"

DataComentario::DataComentario(string codigoProducto, string codigoPadre, string nickname, string texto, DataFecha fecha) {
    this->codigoProducto = codigoProducto;
    this->codigoPadre = codigoPadre;
    this->nickname = nickname;
    this->texto = texto;
    this->fecha = fecha;
}

string DataComentario::getCodigoProducto() {
    return this->codigoProducto;
}

string DataComentario::getCodigoPadre() {
    return this->codigoPadre;
}

string DataComentario::getNickname() {
    return this->nickname;
}

string DataComentario::getTexto() {
    return this->texto;
}

DataFecha DataComentario::getFecha() {
    return this->fecha;
}