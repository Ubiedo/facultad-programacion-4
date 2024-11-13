#include "../include/factory.h"

Factory::Factory() {}
Factory::~Factory() {}

Factory* Factory::getInstancia() {
    if (instancia == NULL) {
        instancia = new Factory();
        return instancia;
    } else {
        return instancia;
    }
}

Factory* Factory::instancia = NULL;

IUsuarios* Factory::getIUsuarios() {
    CtrlUsuarios* res = CtrlUsuarios::getInstancia();
    return res;
}

IPromoProd* Factory::getIPromoProd() {
    CtrlPromoProd* res = CtrlPromoProd::getInstancia();
    return res;
}
