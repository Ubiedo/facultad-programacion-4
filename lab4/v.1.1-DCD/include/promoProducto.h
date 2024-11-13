#ifndef PROMOPRODUCTO
#define PROMOPRODUCTO

#include "promocion.h"
#include "producto.h"

#include <string>

using namespace std;

class PromoProducto {
    private:
        int cantMinima;
        Promocion* promocion;
        Producto* producto;
    public:
        PromoProducto(int cantMinima);
        ~PromoProducto() = default;

        int getCantMinima();
        Promocion* getPromocion();
        Producto* getProducto();

        float getDescuento();
        int getProdTotales();

        string getCodigo();
        void setProdNoti();
};

#endif