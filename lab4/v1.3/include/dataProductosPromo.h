#ifndef DATAPRODUCTOSPROMO
#define DATAPRODUCTOSPROMO

#include "enumCategoria.h"

#include <string>
using namespace std;

class DataProductosPromo {
    private:
        string nombreProducto, descripcionProducto;
        Categoria categoriaProducto;
        float precioProducto;
        int stockProducto, minimoProducto;
    public:
        DataProductosPromo(string nombreProducto, string descripcionProducto, Categoria categoriaProducto, int stockProducto, float precioProducto, int minimoProducto);
        ~DataProductosPromo() = default;

        string getNombreProducto();
        string getDescripcionProducto();
        Categoria getCategoriaProducto();
        int getStockProducto();
        float getPrecioProducto();
        int getMinimoProducto();
};

#endif