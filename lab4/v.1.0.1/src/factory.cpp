#include "../include/factory.h"

Factory::Factory() {}
Factory::~Factory() {}

Factory* Factory::getInstancia() {
    Factory* inst;
    if (instancia == NULL)
        inst = new Factory();
    else
        inst = instancia;
    return inst;
}

IUsuarios* Factory::getIUsuarios() {
    CtrlUsuarios* res = new CtrlUsuarios();
    return res;
}

IPromoProd* Factory::getIPromoProd() {
    CtrlPromoProd* res = new CtrlPromoProd();
    return res;
}

Factory* Factory::instancia = NULL;