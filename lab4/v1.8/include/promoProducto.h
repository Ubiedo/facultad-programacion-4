#ifndef PROMOPRODUCTO
#define PROMOPRODUCTO

#include "promocion.h"
#include "enumCategoria.h"
#include "DataPromoProducto.h"

#include <vector>
using namespace std;

class Producto;

class PromoProducto {
    private:
        int cantMinima;
        Promocion* promocion;
        Producto* producto;
    public:
        PromoProducto(Promocion* promocion, Producto* producto, int cantMinima);
        ~PromoProducto() = default;

        int getCantMinima();
        Promocion* getPromocion();
        Producto* getProducto();

        bool esVigente(DataFecha); //Requerida por Producto para disponibleParaPromocion
        string infoProducto(); //Requerida por Promocion para infoProductos
        string getNombrePromo(); //Requerida por Produto para getCodigoPromo
        bool cumpleRequisito(vector<DataPromoProducto>); //Requerida por Promocion para cumpleRequisitos
};

#include "producto.h"

#endif