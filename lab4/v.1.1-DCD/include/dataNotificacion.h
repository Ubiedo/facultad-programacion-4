#ifndef DATANOTIFICACION
#define DATANOTIFICACION

#include "dataProducto.h"

#include <vector>

using namespace std;

class DataNotificacion {
    private:
        string nickVendedor, nombPromo;
        vector<DataProducto> productos;
    public:
        DataNotificacion(string nickVendedor, string nombPromo, vector<DataProducto> prods);
        ~DataNotificacion() = default;
        
        string getNickVendedor();
        string getNombPromo();
        vector<DataProducto> getProds();
};

#endif