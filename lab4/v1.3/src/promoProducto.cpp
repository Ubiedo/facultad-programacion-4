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

DataProductosPromo PromoProducto::getDataProductosPromo() {
    DataProductosPromo dpp = DataProductosPromo(producto->getNombre(), producto->getDescripcion(), producto->getCategoria(), producto->getStock(), producto->getPrecio(), cantMinima);
    return dpp;
}