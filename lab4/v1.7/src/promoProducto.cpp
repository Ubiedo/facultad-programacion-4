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
    string res = producto->toString() + "Mínimo para promoción: " + to_string(cantMinima) + "\n";
    return res;
}

string PromoProducto::getNombrePromo() {
    return promocion->getNombre();
}

bool PromoProducto::cumpleRequisito(vector<DataPromoProducto> productosCantidad) {
    string codigo = producto->getCodigo();
    bool res = false;
    unsigned int i = 0;
    while ((i < productosCantidad.size()) && (!res)) {
        DataPromoProducto dpp = productosCantidad[i];
        if ((codigo.compare(dpp.getCodigoProducto()) == 0) && (cantMinima <= dpp.getCantidadProducto()))
            res = true;
        i++;
    }
    return res;
}