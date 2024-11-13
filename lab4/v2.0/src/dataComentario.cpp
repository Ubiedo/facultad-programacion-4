#include "../include/dataComentario.h"

DataComentario::DataComentario(string codigo, string strComentario) {
    this->codigo = codigo;
    this->strComentario = strComentario;
}

string DataComentario::getCodigo() {
    return this->codigo;
}

string DataComentario::getStrComentario() {
    return this->strComentario;
}