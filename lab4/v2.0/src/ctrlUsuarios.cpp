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

vector<string> CtrlUsuarios::nicknameVendedores() {
    vector<string> res;
    map<string, Vendedor*>::iterator itV;
    for (itV = vendedores.begin(); itV != vendedores.end(); ++itV)
        res.push_back(itV->second->getNickname());
    return res;
}

vector<string> CtrlUsuarios::nicknameClientes() {
    vector<string> res;
    map<string, Cliente*>::iterator itCl;
    for (itCl = clientes.begin(); itCl != clientes.end(); ++itCl)
        res.push_back(itCl->second->getNickname());
    return res;
}

Vendedor* CtrlUsuarios::findVendedor(string key) {
    if (vendedores.count(key) != 0)
        return vendedores[key];
    else
        return NULL;
}

Cliente* CtrlUsuarios::findCliente(string key) {
    if (clientes.count(key) != 0)
        return clientes[key];
    else
        return NULL;
}

/***********************************ALTA DE USUARIO************************************/

string CtrlUsuarios::crearCliente(string nickname, string contrasena, DataFecha fechaNacimiento, string calle, string nroPuerta, string ciudad) {
    if ((clientes.count(nickname) == 0) && (vendedores.count(nickname) == 0)) {
        Cliente* cl = new Cliente(nickname, contrasena, fechaNacimiento, calle, nroPuerta, ciudad);
        clientes[nickname] = cl;
        return ("Usuario ingresado con éxito\n");
    } else
        return ("[ERROR] Nickname ya en uso\n");
}

string CtrlUsuarios::crearVendedor(string nickname, string contrasena, DataFecha fechaNacimiento, string nroRut) {
    if ((clientes.count(nickname) == 0) && (vendedores.count(nickname) == 0)) {
        Vendedor* v = new Vendedor(nickname, contrasena, fechaNacimiento, nroRut);
        vendedores[nickname] = v;
        return ("Usuario ingresado con éxito\n");
    } else
        return ("[ERROR] Nickname ya en uso\n");
}

/*********************************LISTADO DE USUARIOS**********************************/

vector<DataCliente> CtrlUsuarios::listarClientes() {
    vector<DataCliente> res;
    map<string, Cliente*>::iterator itCl;
    for (itCl = clientes.begin(); itCl != clientes.end(); ++itCl)
        res.push_back(itCl->second->getDataCliente());
    return res;
}

vector<DataVendedor> CtrlUsuarios::listarVendedores() {
    vector<DataVendedor> res;
    map<string, Vendedor*>::iterator itV;
    for (itV = vendedores.begin(); itV != vendedores.end(); ++itV)
        res.push_back(itV->second->getDataVendedor());
    return res;
}

/***********************************DEJAR COMENTARIO***********************************/

string CtrlUsuarios::crearComentario(string codigoProducto, string codigoPadre, string nickname, string texto, DataFecha fecha) {
    Usuario* u;
    if (clientes.count(nickname) != 0) {
        map<string, Cliente*>::iterator itCl = clientes.find(nickname);
        u = itCl->second;
    } else {
        if (vendedores.count(nickname) != 0) {
            map<string, Vendedor*>::iterator itV = vendedores.find(nickname);
            u = itV->second;
        } else
        return "[ERROR] Usuario no encontrado\n";
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
    Producto* prod = cPP->findProducto(codigoProducto);
    if (prod == NULL)
        return "[ERROR] Producto no encontrado\n";

    bool tienePadre (codigoPadre.compare("") != 0);
    Comentario* padre = NULL;
    if (tienePadre) {
        padre = prod->findComentario(codigoPadre);
        if (padre == NULL)
            return "[ERROR] Comentario padre no encontrado\n";
    }

    Comentario* cmt = new Comentario(codigo, texto, fecha, u, prod, padre);

    u->agregarComentario(cmt);
    prod->agregarComentario(cmt);
    if (tienePadre)
        padre->agregarRespuesta(cmt);
    return "Comentario ingresado con éxito\n";
}

/*********************************ELIMINAR COMENTARIO**********************************/

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

vector<DataComentario> CtrlUsuarios::comentariosDeUsuario(string nickname) {
    if (clientes.count(nickname) != 0) {
        Usuario* u = clientes[nickname];
        return u->getComentarios();
    } else {
        if (vendedores.count(nickname) != 0) {
            Usuario* u = vendedores[nickname];
            return u->getComentarios();
        } else {
            vector<DataComentario> res;    
            return res;
        }
    } 
}

string CtrlUsuarios::eliminarComentario(string nickname, string codigo) {
    Usuario* u = NULL;
    if (clientes.count(nickname) != 0)
        u = clientes[nickname];
    else
        if (vendedores.count(nickname) != 0)
            u = vendedores[nickname];
        else  
            return "[ERROR] Usuario no encontrado\n";
    
    if (u != NULL) {
        Comentario* cmt = u->findComentario(codigo);
        if (cmt != NULL) {
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
            return "Comentario(s) eliminado(s) con éxito\n";
        } else
            return "[ERROR] Comentario no encontrado\n";
    } else
        return "[ERROR] Usuario no encontrado\n";
}

/***********************************CREAR PROMOCION************************************/

vector<string> CtrlUsuarios::vendedoresConProductoDisponible(DataFecha fecha) {
    vector<string> res;
    map<string, Vendedor*>::iterator itV;
    for (itV = vendedores.begin(); itV != vendedores.end(); ++itV) 
        if (itV->second->tieneProductoDisponible(fecha))
            res.push_back(itV->second->getNickname());
    return res;
}

vector<DataProdBasica> CtrlUsuarios::productosDisponiblesVendedor(string nickname, DataFecha fecha) {
    if (vendedores.count(nickname) != 0)
        return (vendedores[nickname]->productosDisponibles(fecha));
    else {
        vector<DataProdBasica> dpbNull;
        return dpbNull;
    }
}

/*****************************SUSCRIBIRSE A NOTIFICACIONES*****************************/

vector<string> CtrlUsuarios::vendedoresParaSuscripcion(string nicknameCliente) {
    vector<string> res;
    if (clientes.count(nicknameCliente) != 0) {
        Cliente* cl = clientes[nicknameCliente];
        map<string, Vendedor*>::iterator itV;
        for (itV = vendedores.begin(); itV != vendedores.end(); ++itV)
            if (!cl->estaSuscrito(itV->first))
                res.push_back(itV->first);
    }
    return res;
}

string CtrlUsuarios::realizarSuscripciones(string nicknameCliente, vector<string>nicknameVendedores) {
    if (clientes.count(nicknameCliente) != 0) {
        Cliente* cl = clientes[nicknameCliente];
        for (unsigned int i = 0; i < nicknameVendedores.size(); i++) {
            if ((vendedores.count(nicknameVendedores[i]) != 0) && (!cl->estaSuscrito(nicknameVendedores[i]))) {
                Vendedor* v = vendedores[nicknameVendedores[i]];
                cl->suscribirse(v);
                v->agregar(cl);
            } else
                return "[ERROR] Vendedor no encontrado o suscripción ya existente\n";
        }
    } else
        return "[ERROR] Cliente no encontrado\n";
    return "Suscripcion(es) realizada(s) con éxito\n";
}

/*******************************CONSULTAR NOTIFICACIONES*******************************/

vector<DataNotificacion> CtrlUsuarios::notificacionesCliente(string nicknameCliente) {
    if (clientes.count(nicknameCliente) != 0)
        return clientes[nicknameCliente]->getNotificaciones();
    else {
        vector<DataNotificacion> res;
        return res;
    }
}

/********************************ELIMINAR SUSCRIPCIONES********************************/

vector<string> CtrlUsuarios::suscripcionesDeCliente(string nicknameCliente) {
    if (clientes.count(nicknameCliente) != 0)
        return clientes[nicknameCliente]->getSuscripciones();
    else {
        vector<string> res;
        return res;
    }
}

string CtrlUsuarios::eliminarSuscripciones(string nicknameCliente, vector<string> suscripcionesAEliminar) {
    if (clientes.count(nicknameCliente) != 0) {
        Cliente* cl = clientes[nicknameCliente];
        for (unsigned int i = 0; i < suscripcionesAEliminar.size(); i++) {
            if (vendedores.count(suscripcionesAEliminar[i]) != 0) {
                Vendedor* v = vendedores[suscripcionesAEliminar[i]];
                cl->desuscribirse(v);
                v->quitar(cl);
            } else
                return "[ERROR] Vendedor no encontrado\n";
        }
    } else
        return "[ERROR] Cliente no encontrado\n";
    return "Suscripcion(es) eliminada(s) con éxito\n";
}

/************************************ENVIAR PRODUCTO***********************************/

vector<DataProdBasica> CtrlUsuarios::enviosPendientesVendedor(string nickname) {
    if (vendedores.count(nickname) != 0)
        return vendedores[nickname]->enviosPendientes();
    else {
        vector<DataProdBasica> res;
        return res;
    }
}

/*********************************EXPEDIENTE DE USUARIO********************************/

bool CtrlUsuarios::esCliente(string nickname) {
    return (clientes.count(nickname) != 0);
}

DataCliente CtrlUsuarios::getDataCliente(string nickname) {
    if (clientes.count(nickname) != 0)
        return clientes[nickname]->getDataCliente();
    else {
        DataFecha fNull = DataFecha();
        DataCliente res = DataCliente("", fNull, "", "", "");
        return res;
    }
}

DataVendedor CtrlUsuarios::getDataVendedor(string nickname) {
    if (vendedores.count(nickname) != 0)
        return vendedores[nickname]->getDataVendedor();
    else {
        DataFecha fNull = DataFecha();
        DataVendedor res = DataVendedor("", fNull, "");
        return res;
    }
}

vector<DataCompraExp> CtrlUsuarios::getCompraExpediente(string nickname) {
    if (clientes.count(nickname) != 0)
        return clientes[nickname]->getCompraExpediente();
    else {
        vector<DataCompraExp> res;
        return res;
    }
}

vector<DataProducto> CtrlUsuarios::getProductosVendedor(string nickname) {
    if (vendedores.count(nickname) != 0)
        return vendedores[nickname]->getProductos();
    else {
        vector<DataProducto> res;
        return res;
    }
}

vector<DataPromoConsulta> CtrlUsuarios::getPromosVendedor(string nickname, DataFecha fecha) {
    if (vendedores.count(nickname) != 0)
        return vendedores[nickname]->getPromosVigentes(fecha);
    else {
        vector<DataPromoConsulta> res;
        return res;
    }
}