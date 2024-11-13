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

DataProdPromo PromoProducto::infoProducto() {
    DataProdPromo dPP = DataProdPromo(producto->getNombre(), producto->getDescripcion(), producto->getCategoria(), producto->getStock(), producto->getPrecio(), cantMinima);
    return dPP;
}

bool PromoProducto::cumpleRequisito(vector<DataProdCantidad> productosCantidad) {
    string codigo = producto->getCodigo();
    bool res = false;
    unsigned int i = 0;
    while ((i < productosCantidad.size()) && (!res)) {
        DataProdCantidad dpp = productosCantidad[i];
        if ((codigo.compare(dpp.getCodigoProducto()) == 0) && (cantMinima <= dpp.getCantidadProducto()))
            res = true;
        i++;
    }
    return res;
}