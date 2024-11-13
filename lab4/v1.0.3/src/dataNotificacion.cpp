#include "../include/dataNotificacion.h"

DataNotificacion::DataNotificacion(string nickVendedor, string nombPromo, set<DataProducto> productos) {
    this->nickVendedor = nickVendedor;
    this->nombPromo = nombPromo;
    this->productos = productos;
}

DataNotificacion::~DataNotificacion(){}

string DataNotificacion::getNickVendedor() {
    return this->nickVendedor;
}

string DataNotificacion::getNombPromo() {
    return this->nombPromo;
}

set<DataProducto> DataNotificacion::getProductos() {
    return this->productos;
}