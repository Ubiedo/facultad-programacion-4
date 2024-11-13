#include "../include/ctrlUsuarios.h"

string CtrlUsuarios::crearCliente(DataCliente dc) {
    if ((clientes.count(dc.getNickname()) == 0) && (vendedores.count(dc.getNickname()) == 0)) {
        Cliente* cl = new Cliente(dc);
        this->clientes[dc.getNickname()] = cl;
        return ("Usuario ingresado con éxito\n");
    } else
        return ("ERROR: Nickname ya en uso\n");
}

string CtrlUsuarios::crearVendedor(DataVendedor dv) {
    if ((clientes.count(dv.getNickname()) == 0) && (vendedores.count(dv.getNickname()) == 0)) {
        Vendedor* v = new Vendedor(dv);
        this->vendedores[dv.getNickname()] = v;
        return ("Usuario ingresado con éxito\n");
    } else
        return ("ERROR: Nickname ya en uso\n");
}

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

void CtrlUsuarios::vaciarUsuarios() {
    map<string, Cliente*>::iterator itCl;
    for (itCl = clientes.begin(); itCl != clientes.end(); ++itCl)
        delete itCl->second;
    clientes.erase(clientes.begin(), clientes.end());

    map<string, Vendedor*>::iterator itV;
    for (itV = vendedores.begin(); itV != vendedores.end(); ++itV)
        delete itV->second;
    vendedores.erase(vendedores.begin(), vendedores.end());
}