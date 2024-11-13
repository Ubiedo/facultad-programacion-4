#ifndef DATAPROMOCION
#define DATAPROMOCION

#include "dataFecha.h"
#include "dataPromoProducto.h"

#include <vector>
#include <string>
using namespace std;

class DataPromocion {
    private:
        string nickname, nombre, descripcion;
        float descuento;
        DataFecha vencimiento;
        vector<DataPromoProducto> productosPromocion;
    public:
        DataPromocion(string nickname, vector<DataPromoProducto> productosPromocion, string nombre, string descripcion, float descuento, DataFecha vencimiento);
        ~DataPromocion() = default;

        string getNickname();
        vector<DataPromoProducto> getProductosPromocion();
        string getNombre();
        string getDescripcion();
        float getDescuento();
        DataFecha getVencimiento();
};

#endif