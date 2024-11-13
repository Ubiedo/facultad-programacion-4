#include "../include/dataCmtBasica.h"

DataCmtBasica::DataCmtBasica(string codigo, string strComentario) {
    this->codigo = codigo;
    this->strComentario = strComentario;
}

string DataCmtBasica::getCodigo() {
    return this->codigo;
}

string DataCmtBasica::getStrComentario() {
    return this->strComentario;
}