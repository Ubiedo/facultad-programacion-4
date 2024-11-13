#include "../include/producto.h"

Producto::Producto(int id, string nombre, string descripcion, Categoria categoria, int stock, float precio) {
    this->id = id;
    this->vendedor = NULL;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->categoria = categoria;
    this->stock = stock;
    this->precio = precio;
}

int Producto::getId() {
    return this->id;
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

DataProdConsulta Producto::getDataProdConsulta() {
    string nicknameVendedor = this->vendedor->getNickname();
    string descripcion = this->descripcion;
    Categoria categoria = this->categoria;
    int stock = this->stock;
    float precio = this->precio;
    DataProdConsulta dpc = DataProdConsulta(nicknameVendedor, descripcion, categoria, stock, precio);
    return dpc;
}

void Producto::setVendedor(Vendedor* vendedor) {
    this->vendedor = vendedor;
}

void Producto::setStock(int stock) {
    this->stock = stock;
}

void Producto::setPrecio(float precio) {
    this->precio = precio;
}