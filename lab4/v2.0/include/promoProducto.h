#ifndef PROMOPRODUCTO
#define PROMOPRODUCTO

#include "promocion.h"
#include "enumCategoria.h"
#include "dataProdPromo.h"
#include "dataProdCantidad.h"

#include <vector>
using namespace std;

class Producto;

class PromoProducto {
    private:
        int cantMinima;
        Promocion* promocion;
        Producto* producto;
    public:
        PromoProducto(Promocion*, Producto*, int);
        ~PromoProducto() = default;

        int getCantMinima();
        Promocion* getPromocion();
        Producto* getProducto();

        DataProdPromo infoProducto(); //Requerida por Promocion para infoProductos
        bool cumpleRequisito(vector<DataProdCantidad>); //Requerida por Promocion para cumpleRequisitos
};

#include "producto.h"

#endif