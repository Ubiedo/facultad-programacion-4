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

CtrlUsuarios* CtrlUsuarios::instancia = NULL;

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

//Alta de Producto

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

//Dejar Comentario

vector<string> CtrlUsuarios::nicknameUsuarios() {
    vector<string> res;
    map<string, Cliente*>::iterator itCl;
    for (itCl = clientes.begin(); itCl != clientes.end(); ++itCl)
        res.push_back(itCl->second->getNickname());
    map<string, Vendedor*>::iterator itV;
    for (itV = vendedores.begin(); itV != vendedores.end(); ++itV)
        res.push_back(itV->second->getNickname());
    return res;
}

void CtrlUsuarios::crearComentario(DataComentario dCmt) {
    Usuario* u;
    if (clientes.count(dCmt.getNickname()) != 0) {
        map<string, Cliente*>::iterator itCl = clientes.find(dCmt.getNickname());
        u = itCl->second;
    } else {
        map<string, Vendedor*>::iterator itV = vendedores.find(dCmt.getNickname());
        u = itV->second;
    }
    
    int id = this->generadorCodigoComentario;
    this->generadorCodigoComentario++;
    string strId;
    if (id < 10)
        strId = "0" + to_string(id);
    else
        strId = to_string(id);
    string codigo = "cmt" + strId;

    CtrlPromoProd* cPP = CtrlPromoProd::getInstancia();
    Producto* prod = cPP->findProducto(dCmt.getCodigoProducto());

    bool tienePadre (dCmt.getCodigoPadre().compare("") != 0);
    Comentario* padre = NULL;
    if (tienePadre)
        padre = prod->findComentario(dCmt.getCodigoPadre());

    Comentario* cmt = new Comentario(codigo, dCmt.getTexto(), dCmt.getFecha(), u, prod, padre);

    u->agregarComentario(cmt);
    prod->agregarComentario(cmt);
    if (tienePadre)
        padre->agregarRespuesta(cmt);
}

//Eliminar Comentario

bool CtrlUsuarios::isEmptyComentarios() {
    map<string, Vendedor*>::iterator itV = vendedores.begin();
    while ((itV != vendedores.end()) && (itV->second->isEmptyComentarios()))
        ++itV;
    if (itV != vendedores.end())
        return false;
    else {
        map<string, Cliente*>::iterator itCl = clientes.begin();
        while ((itCl != clientes.end()) && (itCl->second->isEmptyComentarios()))
            ++itCl;
        if (itCl != clientes.end())
            return false;
        else
            return true;
    }
}

vector<string> CtrlUsuarios::usuariosConComentarios() {
    vector<string> res;
    map<string, Cliente*>::iterator itCl;
    for (itCl = clientes.begin(); itCl != clientes.end(); ++itCl)
        if (!(itCl->second->isEmptyComentarios()))
            res.push_back(itCl->second->getNickname());
    map<string, Vendedor*>::iterator itV;
    for (itV = vendedores.begin(); itV != vendedores.end(); ++itV)
        if (!(itV->second->isEmptyComentarios()))
            res.push_back(itV->second->getNickname());
    return res;
}

vector<DataCmtBasica> CtrlUsuarios::comentariosDeUsuario(string nickname) {
    Usuario* u;
    if (clientes.count(nickname) != 0) {
        u = clientes[nickname];
    } else {
        u = vendedores[nickname];
    }
    return u->getComentarios();
}

void CtrlUsuarios::eliminarComentario(string nickname, string codigo) {
    Usuario* u;
    if (clientes.count(nickname) != 0) {
        u = clientes[nickname];
    } else {
        u = vendedores[nickname];
    }
    Comentario* cmt = u->findComentario(codigo);
    cmt->getUsuario()->removerComentario(codigo);
    cmt->getProducto()->removerComentario(codigo);
    if (cmt->getPadre() != NULL) {
        cmt->getPadre()->removerRespuesta(codigo);
    }
    vector<Comentario*> respuestas = cmt->getRespuestas();
    for (unsigned int i = 0; i < respuestas.size(); i++) {
        eliminarComentario(respuestas[i]->getUsuario()->getNickname(), respuestas[i]->getCodigo());
    }
    delete cmt;
}

//Requeridas por CtrlPromoProd

Vendedor* CtrlUsuarios::findVendedor(string key) {
    return vendedores[key];
}
