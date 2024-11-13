#include "../include/fechaSistema.h"

FechaSistema::FechaSistema() {}
FechaSistema::~FechaSistema() {}

FechaSistema* FechaSistema::getInstancia() {
    if (instancia == NULL) {
        instancia = new FechaSistema();
        return instancia;
    } else {
        return instancia;
    }
}

FechaSistema* FechaSistema::instancia = NULL;

DataFecha FechaSistema::getFecha() {
    return this->fecha;
}

void FechaSistema::setFecha(DataFecha fecha) {
    this->fecha = fecha;
}