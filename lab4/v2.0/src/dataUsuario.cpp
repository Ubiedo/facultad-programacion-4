#include "../include/dataUsuario.h"

DataUsuario::DataUsuario() {}

DataUsuario::~DataUsuario() {}

string DataUsuario::getNickname() {
    return this->nickname;
}

DataFecha DataUsuario::getFechaNacimiento() {
    return this->fechaNacimiento;
}