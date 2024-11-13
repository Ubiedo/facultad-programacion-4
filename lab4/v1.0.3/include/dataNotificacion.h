#ifndef DATANOTIFICACION
#define DATANOTIFICACION

#include "dataProducto.h"

#include <set>

using namespace std;

class DataNotificacion {
    private:
        string nickVendedor, nombPromo;
        set<DataProducto> productos;
    public:
        DataNotificacion(string nickVendedor, string nombPromo, set<DataProducto> productos);
        ~DataNotificacion();
        
        string getNickVendedor();
        string getNombPromo();
        set<DataProducto> getProductos();
};

#endif