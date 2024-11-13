#ifndef DATACOMPRA
#define DATACOMPRA

#include "dataFecha.h"
#include "dataProdPrecio.h"

#include <vector>
#include <string>
using namespace std;

class DataCompra {
    private:
        float monto;
        DataFecha fecha;
        vector<DataProdPrecio> productos;
    public:
        DataCompra(float, DataFecha, vector<DataProdPrecio>);
        ~DataCompra() = default;

        float getMonto();
        DataFecha getFecha();
        vector<DataProdPrecio> getProductos();
};

#endif