#include "../include/dataNotificacion.h"

DataNotificacion::DataNotificacion(string nicknameVendedor, string nombrePromo, vector<DataProdBasica> productosPromo) {
    this->nicknameVendedor = nicknameVendedor;
    this->nombrePromo = nombrePromo;
    this->productosPromo = productosPromo;
}

string DataNotificacion::getNicknameVendedor() {
    return nicknameVendedor;
}

string DataNotificacion::getNombrePromo() {
    return nombrePromo;
}

vector<DataProdBasica> DataNotificacion::getProductosPromo() {
    return productosPromo;
}