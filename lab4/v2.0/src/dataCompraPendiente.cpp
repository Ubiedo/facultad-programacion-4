#include "../include/dataCompraPendiente.h"

DataCompraPendiente::DataCompraPendiente(string codigo, string nickname, DataFecha fecha) {
    this->codigo = codigo;
    this->nickname = nickname;
    this->fecha = fecha;
}

string DataCompraPendiente::getCodigo() {
    return codigo;
}

string DataCompraPendiente::getNickname() {
    return nickname;
}

DataFecha DataCompraPendiente::getFecha() {
    return fecha;
}