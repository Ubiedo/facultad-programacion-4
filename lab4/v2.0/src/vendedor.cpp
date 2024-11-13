#include "../include/vendedor.h"

Vendedor::Vendedor(string nickname, string contrasena, DataFecha fechaNacimiento, string nroRut) {
    this->nickname = nickname;
    this->contrasena = contrasena;
    this->fechaNacimiento = fechaNacimiento;
    this->nroRut = nroRut;
}

Vendedor::~Vendedor() {
    map<string, Comentario*>::iterator itCmt;
    for (itCmt = comentarios.begin(); itCmt != comentarios.end(); ++itCmt)
        delete itCmt->second;
}

string Vendedor::getNroRut() {
    return this->nroRut;
}

DataVendedor Vendedor::getDataVendedor() {
    DataVendedor dVd = DataVendedor(nickname, fechaNacimiento, nroRut);
    return dVd;
}

void Vendedor::agregarProducto(Producto* prod) {
    productos[prod->getCodigo()] = prod;
}

void Vendedor::agregarPromocion(Promocion* promo) {
    promociones[promo->getNombre()] = promo;
}

bool Vendedor::tieneProductoDisponible(DataFecha fecha) {
    map<string, Producto*>::iterator itPrd = productos.begin();
    while ((itPrd != productos.end()) && (!itPrd->second->sinPromoVigente(fecha)))
        ++itPrd;
    return (itPrd != productos.end());
}

vector<DataProdBasica> Vendedor::productosDisponibles(DataFecha fecha) {
    vector<DataProdBasica> res;
    map<string, Producto*>::iterator itPrd;
    for (itPrd = productos.begin(); itPrd != productos.end(); ++itPrd)
        if (itPrd->second->sinPromoVigente(fecha))
            res.push_back(itPrd->second->getDataProdBasica());
    return res;
}

vector<DataProdBasica> Vendedor::enviosPendientes() {
    vector<DataProdBasica> res;
    map<string, Producto*>::iterator itPrd;
    for (itPrd = productos.begin(); itPrd != productos.end(); ++itPrd)
        if (itPrd->second->tieneEnvioPendiente()) {
            DataProdBasica dpb = DataProdBasica(itPrd->first, itPrd->second->getNombre());
            res.push_back(dpb);
        }
    return res;
}

vector<DataProducto> Vendedor::getProductos() {
    vector<DataProducto> res;
    map<string, Producto*>::iterator itPrd;
    for (itPrd = productos.begin(); itPrd != productos.end(); ++itPrd) {
        Producto* prod = itPrd->second;
        DataProducto dPrd = DataProducto(prod->getCodigo(), prod->getNombre(), prod->getDescripcion(), prod->getCategoria(), prod->getStock(), prod->getPrecio());
        res.push_back(dPrd);
    }
    return res;
}

vector<DataPromoConsulta> Vendedor::getPromosVigentes(DataFecha fecha) {
    vector<DataPromoConsulta> res;
    map<string, Promocion*>::iterator itPrm;
    for (itPrm = promociones.begin(); itPrm != promociones.end(); ++itPrm)
        if (itPrm->second->esVigente(fecha))
            res.push_back(itPrm->second->getDataPromoConsulta());
    return res;
}