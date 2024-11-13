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

vector<DataCmtBasica> Producto::getComentarios() {
    vector<DataCmtBasica> res;
    map<string, Comentario*>::iterator itCmt;
    for (itCmt = comentarios.begin(); itCmt != comentarios.end(); ++itCmt) {
        res.push_back(itCmt->second->getDataCmtBasica());
    }
    return res;
}

Comentario* Producto::findComentario(string codigo) {
    return comentarios[codigo];
}

bool Producto::tieneComentarios() {
    return (!comentarios.empty());
}

void Producto::agregarComentario(Comentario* cmt) {
    comentarios[cmt->getCodigo()] = cmt;
}

void Producto::removerComentario(string codigo) {
    comentarios.erase(codigo);
}

bool Producto::disponibleParaPromocion(DataFecha fecha) {
    if ((this->promocion != NULL) && (this->promocion->esVigente(fecha)))
        return false;
    else
        return true;
}

void Producto::setPP(PromoProducto* pp) {
    promocion = pp;
}

string Producto::toString() {
    string strCategoria;
    if (categoria == ropa)
        strCategoria = "Ropa";
    else if (categoria == electrodomestico)
        strCategoria = "Electrodoméstico";
    else
        strCategoria = "Otro";
    string strPrecio = to_string(precio);
    strPrecio.erase(strPrecio.end() - 4, strPrecio.end());
    string res = ("Nombre: " + nombre + "\nDescripción: " + descripcion + "\nCategoría: " 
    + strCategoria + "\nStock: " + to_string(stock) + "\nPrecio: UYU " + strPrecio + "\n");
    return res;
}

DataProdCompra Producto::getDataProdCompra() {
    DataProdCompra dpc = DataProdCompra(codigo, nombre, stock);
    return dpc;
}

string Producto::getNombrePromo() {
    return promocion->getNombrePromo();
}

void Producto::agregarCP(CompraProducto* cp, string codigo) {
    compras[codigo] = cp;
}

void Producto::disminuirStock(int cantidad) {
    stock = stock - cantidad;
}