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

string Vendedor::toString() {
    string res = "Nickname: " + this->nickname + "\n" 
    + "Fecha de nacimiento: " + this->fechaNacimiento.toString() + "\n" 
    + "Número de RUT: " + this->nroRut + "\n";
    return res;
}

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

DataVendedor Vendedor::getDataVendedor(){
    return DataVendedor(this->nickname, this->contrasena, this->fechaNacimiento, this->nroRut);
}

set<string> Vendedor::getNombresDeProductosEnVenta(){
    set<string> nombres;
    map<string, Producto*>::iterator it;
    for(it = this->productos.begin(); it != this->productos.end(); ++it){
        nombres.insert(it->second->getNombre());
    }
    if(nombres.empty())
        nombres.insert("No tiene productos en venta");
    return nombres;
}

set<string> Vendedor::getNombresDePromocionesVigente() {
    set<string> nombres;
    map<string, Promocion*>::iterator it;
    for(it = this->promociones.begin(); it != this->promociones.end(); ++it){
        nombres.insert(it->second->getNombre());
    }
    if(nombres.empty())
        nombres.insert("No tiene promociones vigentes");
    return nombres;
}