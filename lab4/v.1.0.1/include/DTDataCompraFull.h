#ifndef DTDATACOMPRAFULL
#define DTDATACOMPRAFULL

#include "dataProducto.h"

class DTDataCompraFull {
    private:
        Fecha fecha;
        vector<DataProductos> productos;
        float monto;
    public:
        DTDataCompraFull(Fecha fecha, DataProductos producto, float monto);
        ~DTDataCompraFull() = default;

        Fecha getFecha();
        DataProducto getProductos();
        float getMonto();
};

#endif