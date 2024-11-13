#ifndef DATACOMPRAFULL
#define DATACOMPRAFULL

#include "dataProducto.h"
#include "dataFecha.h"

#include <vector>

class DataCompraFull {
    private:
        DataFecha fecha;
        vector<DataProducto> productos;
        float monto;
    public:
        DataCompraFull(DataFecha fecha, DataProducto producto, float monto);
        ~DataCompraFull() = default;

        DataFecha getFecha();
        DataProducto getProductos();
        float getMonto();
};

#endif