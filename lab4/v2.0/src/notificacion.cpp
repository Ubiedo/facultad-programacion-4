#include "../include/notificacion.h"

Notificacion::Notificacion(string codigo, string nicknameVendedor, string nombrePromo, vector<DataProdBasica> productosPromo) {
    this->codigo = codigo;
    this->nicknameVendedor = nicknameVendedor;
    this->nombrePromo = nombrePromo;
    this->productosPromo = productosPromo;
}

string Notificacion::getCodigo() {
    return codigo;
}

string Notificacion::getNicknameVendedor() {
    return nicknameVendedor;
}

string Notificacion::getNombrePromo() {
    return nombrePromo;
}

vector<DataProdBasica> Notificacion::getProductosPromo() {
    return productosPromo;
}

DataNotificacion Notificacion::getDataNotificacion() {
    DataNotificacion dN = DataNotificacion(nicknameVendedor, nombrePromo, productosPromo);
    return dN;
}