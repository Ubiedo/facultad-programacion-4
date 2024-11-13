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

void Producto::setStock(int stock) {
    this->stock = stock;
}

void Producto::setPrecio(float precio) {
    this->precio = precio;
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