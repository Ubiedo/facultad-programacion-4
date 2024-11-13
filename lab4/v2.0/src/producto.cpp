#include "../include/producto.h"

Producto::Producto(Vendedor* vendedor, string codigo, string nombre, string descripcion, Categoria categoria, int stock, float precio) {
    this->vendedor = vendedor;
    this->codigo = codigo;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->categoria = categoria;
    this->stock = stock;
    this->precio = precio;
}

string Producto::getCodigo() {
    return this->codigo;
}

Vendedor* Producto::getVendedor() {
    return this->vendedor;
}

string Producto::getNombre() {
    return this->nombre;
}

string Producto::getDescripcion() {
    return this->descripcion;
}

Categoria Producto::getCategoria() {
    return this->categoria;
}

int Producto::getStock() {
    return this->stock;
}

float Producto::getPrecio() {
    return this->precio;
}

DataProdBasica Producto::getDataProdBasica() {
    DataProdBasica dpb = DataProdBasica(codigo, nombre);
    return dpb;
}

DataProdConsulta Producto::getDataProdConsulta() {
    string nicknameVendedor = this->vendedor->getNickname();
    string descripcion = this->descripcion;
    Categoria categoria = this->categoria;
    int stock = this->stock;
    float precio = this->precio;
    DataProdConsulta dpc = DataProdConsulta(nicknameVendedor, descripcion, categoria, stock, precio);
    return dpc;
}

DataProdCompra Producto::getDataProdCompra() {
    DataProdCompra dpc = DataProdCompra(codigo, nombre, stock);
    return dpc;
}

vector<DataComentario> Producto::getComentarios() {
    vector<DataComentario> res;
    map<string, Comentario*>::iterator itCmt;
    for (itCmt = comentarios.begin(); itCmt != comentarios.end(); ++itCmt) {
        res.push_back(itCmt->second->getDataComentario());
    }
    return res;
}

Comentario* Producto::findComentario(string codigo) {
    if (comentarios.count(codigo) != 0)
        return comentarios[codigo];
    else
        return NULL;
}

void Producto::agregarComentario(Comentario* cmt) {
    comentarios[cmt->getCodigo()] = cmt;
}

void Producto::removerComentario(string codigo) {
    comentarios.erase(codigo);
}

bool Producto::sinPromoVigente(DataFecha fecha) {
    if ((this->promocion != NULL) && (this->promocion->getPromocion()->esVigente(fecha)))
        return false;
    else
        return true;
}

void Producto::setPP(PromoProducto* pp) {
    promocion = pp;
}

string Producto::getNombrePromo() {
    return promocion->getPromocion()->getNombre();
}

void Producto::agregarCP(CompraProducto* cp, string codigo) {
    enviosPendientes[codigo] = cp;
}

void Producto::disminuirStock(int cantidad) {
    stock = stock - cantidad;
}

bool Producto::tieneEnvioPendiente() {
    return (!enviosPendientes.empty());
}

vector<DataCompraPendiente> Producto::getComprasPendientes() {
    vector<DataCompraPendiente> res;
    map<string, CompraProducto*>::iterator itCmp;
    for (itCmp = enviosPendientes.begin(); itCmp != enviosPendientes.end(); ++itCmp) {
        DataCompraPendiente dcp = DataCompraPendiente(itCmp->first, itCmp->second->getCompra()->getCliente()->getNickname(), itCmp->second->getCompra()->getFecha());
        res.push_back(dcp);
    }
    return res;
}

string Producto::marcarComoEnviado(string codigoCompra) {
    if (enviosPendientes.count(codigoCompra) != 0) {
        enviosPendientes[codigoCompra]->marcarComoEnviado();
        enviosPendientes.erase(codigoCompra);
        return "Producto enviado con éxito\n";
    } else
        return "[ERROR] Compra no encontrada\n";
}