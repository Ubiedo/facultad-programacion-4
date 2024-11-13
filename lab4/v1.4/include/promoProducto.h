#ifndef PROMOPRODUCTO
#define PROMOPRODUCTO

#include "promocion.h"
#include "enumCategoria.h"

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
};

#include "producto.h"

#endif