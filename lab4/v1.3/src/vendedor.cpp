#include "../include/vendedor.h"

Vendedor::Vendedor(DataVendedor dv) {
    this->nickname = dv.getNickname();
    this->contrasena = dv.getContrasena();
    this->fechaNacimiento = dv.getFechaNacimiento();
    this->nroRut = dv.getNroRut();
}

Vendedor::~Vendedor() {
    map<string, Comentario*>::iterator itCmt;
    for (itCmt = comentarios.begin(); itCmt != comentarios.end(); ++itCmt)
        delete itCmt->second;
}

string Vendedor::getNroRut() {
    return this->nroRut;
}

void Vendedor::setNroRut(string nroRut) {
    this->nroRut = nroRut;
}

string Vendedor::toString() {
    string res = "Nickname: " + this->nickname + "\n" 
    + "Fecha de nacimiento: " + this->fechaNacimiento.toString() + "\n" 
    + "Número de RUT: " + this->nroRut + "\n";
    return res;
}

//Requeridas por CtrlPromoProd

void Vendedor::agregarProducto(Producto* prod) {
    productos[prod->getCodigo()] = prod;
}

bool Vendedor::tieneProductoDisponible(DataFecha fecha) {
    map<string, Producto*>::iterator itPrd = productos.begin();
    while ((itPrd != productos.end()) && (!itPrd->second->disponibleParaPromocion(fecha)))
        ++itPrd;
    return (itPrd != productos.end());
}

vector<DataProdBasica> Vendedor::productosDisponibles(DataFecha fecha) {
    vector<DataProdBasica> res;
    map<string, Producto*>::iterator itPrd;
    for (itPrd = productos.begin(); itPrd != productos.end(); ++itPrd)
        if (itPrd->second->disponibleParaPromocion(fecha))
            res.push_back(itPrd->second->getDataProdBasica());
    return res;
}

void Vendedor::agregarPromocion(Promocion* promo) {
    promociones[promo->getNombre()] = promo;
}