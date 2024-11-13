#include "../include/promoProducto.h"

PromoProducto::PromoProducto(Promocion* promocion, Producto* producto, int cantMinima) {
    this->promocion = promocion;
    this->producto = producto;
    this->cantMinima = cantMinima;
}

int PromoProducto::getCantMinima() {
    return this->cantMinima;
}

Promocion* PromoProducto::getPromocion() {
    return this->promocion;
}

Producto* PromoProducto::getProducto() {
    return this->producto;
}

bool PromoProducto::esVigente(DataFecha fecha) {
    return (promocion->esVigente(fecha));
}

string PromoProducto::infoProducto() {
    string categoria;
    if (producto->getCategoria() == ropa)
        categoria = "Ropa";
    else if (producto->getCategoria() == electrodomestico)
        categoria = "Electrodoméstico";
    else
        categoria = "Otro";
    string precio = to_string(producto->getPrecio());
    precio.erase(precio.end() - 4, precio.end());
    string res = ("Nombre: " + producto->getNombre() + "\nDescripción: " + producto->getDescripcion() 
    + "\nCategoría: " + categoria + "\nStock: " + to_string(producto->getStock()) + "\nPrecio: UYU " 
    + precio + "\nMínimo para promoción: " + to_string(cantMinima) + "\n");
    return res;
}