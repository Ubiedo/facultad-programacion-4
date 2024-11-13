#ifndef DATAPRODCANTIDAD
#define DATAPRODCANTIDAD

#include <string>
using namespace std;

class DataProdCantidad {
    private:
        string codigoProducto;
        int cantidadProducto;
    public:
        DataProdCantidad(string codigoProducto, int cantidadProducto);
        ~DataProdCantidad() = default;

        string getCodigoProducto();
        int getCantidadProducto();
};

#endif