#include "../include/ctrlUsuarios.h"

CtrlUsuarios::CtrlUsuarios() {}
CtrlUsuarios::~CtrlUsuarios() {
    map<string, Cliente*>::iterator itCl;
    for (itCl = clientes.begin(); itCl != clientes.end(); ++itCl)
        delete itCl->second;

    map<string, Vendedor*>::iterator itV;
    for (itV = vendedores.begin(); itV != vendedores.end(); ++itV)
        delete itV->second;
}

CtrlUsuarios* CtrlUsuarios::getInstancia() {
    if (instancia == NULL) {
        instancia = new CtrlUsuarios();
        return instancia;
    } else {
        return instancia;
    }
}

//Alta de Usuario

string CtrlUsuarios::crearCliente(DataCliente dc) {
    if ((clientes.count(dc.getNickname()) == 0) && (vendedores.count(dc.getNickname()) == 0)) {
        Cliente* cl = new Cliente(dc);
        clientes[dc.getNickname()] = cl;
        return ("Usuario ingresado con éxito\n");
    } else
        return ("ERROR: Nickname ya en uso\n");
}

string CtrlUsuarios::crearVendedor(DataVendedor dv) {
    if ((clientes.count(dv.getNickname()) == 0) && (vendedores.count(dv.getNickname()) == 0)) {
        Vendedor* v = new Vendedor(dv);
        vendedores[dv.getNickname()] = v;
        return ("Usuario ingresado con éxito\n");
    } else
        return ("ERROR: Nickname ya en uso\n");
}

//Listado de Usuarios

vector<string> CtrlUsuarios::listarUsuarios() {
    vector<string> res;
    map<string, Cliente*>::iterator itCl;
    for (itCl = clientes.begin(); itCl != clientes.end(); ++itCl)
        res.push_back(itCl->second->toString());

    map<string, Vendedor*>::iterator itV;
    for (itV = vendedores.begin(); itV != vendedores.end(); ++itV)
        res.push_back(itV->second->toString());

    return res;
}

//Requeridas por CtrlPromoProd

bool CtrlUsuarios::isEmptyVendedores() {
    return (vendedores.empty());
}

vector<string> CtrlUsuarios::nicknameVendedores() {
    vector<string> res;
    map<string, Vendedor*>::iterator itV;
    for (itV = vendedores.begin(); itV != vendedores.end(); ++itV)
        res.push_back(itV->second->getNickname());
    return res;
}

Vendedor* CtrlUsuarios::getVendedor(string nickname) { //Pre-C: Existe el vendedor con nickname dado
    return vendedores[nickname];
}

CtrlUsuarios* CtrlUsuarios::instancia = NULL;

// Suscribirse a Notificaciones
set<string> CtrlUsuarios::getVendedoresNoSuscritos(string cliente){
    Cliente* cl = this->clientes[cliente];
    set<string> imprimir;
    map<string, Vendedor*>::iterator it;
    for (it= vendedores.begin(); it!=vendedores.end(); ++it){
        if (!(cl->suscritoAVendedor(it->second))){
            imprimir.insert(it->first);
        }
    }
    return (imprimir);
}

void CtrlUsuarios::suscribirAlVendedor(string cliente, string vendedor){
    Cliente* cl = this->clientes[cliente];
    Vendedor* v = this->vendedores[vendedor];
    cl->suscribirAVendedor(v);
}



// Consulta a Notificaciones
set<DataNotificacion> CtrlUsuarios::getNotificacionesDeCliente(string cliente){
    // encotrar cliente
    Cliente* cl = this->clientes[cliente];
    // devolver notificaciones
    return (cl->getNotificaciones());
}

void CtrlUsuarios::vaciarNotificaciones(string cliente){
    Cliente* cl = this->clientes[cliente];
    cl->vaciarNotificaciones();
}

// Eliminar suscripciones
set<string> CtrlUsuarios::getSuscripcionesDeCliente(string cliente){
    Cliente* cl = this->clientes[cliente];
    set<string> imprimir;
    map<string, Vendedor*>::iterator it;
    for (it= vendedores.begin(); it!=vendedores.end(); ++it){
        if (cl->suscritoAVendedor(it->second)){
            imprimir.insert(it->first);
        }
    }
    return (imprimir);
}

void CtrlUsuarios::eliminarSuscripcionClienteAVendedor(string cliente, string vendedor){
    Cliente* cl = this->clientes[cliente];
    Vendedor* v = this->vendedores[vendedor];
    cl->desuscribir(v);
}