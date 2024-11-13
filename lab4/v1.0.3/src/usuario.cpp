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

void Usuario::setNickname(string nickname) {
    this->nickname = nickname;
}

void Usuario::setContrasena(string contrasena) {
    this->contrasena = contrasena;
}

void Usuario::setFechaNacimiento(DataFecha fechaNacimiento) {
    this->fechaNacimiento = fechaNacimiento;
}