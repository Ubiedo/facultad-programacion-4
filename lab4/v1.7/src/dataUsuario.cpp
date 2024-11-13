#include "../include/dataUsuario.h"

DataUsuario::DataUsuario() {}

DataUsuario::~DataUsuario() {}

string DataUsuario::getNickname() {
    return this->nickname;
}

string DataUsuario::getContrasena() {
    return this->contrasena;
}

DataFecha DataUsuario::getFechaNacimiento() {
    return this->fechaNacimiento;
}