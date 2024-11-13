#ifndef COMPRAPRODUCTO
#define COMPRAPRODUCTO

#include "enumEstadoEnvio.h"

class Producto;
class Compra;

class CompraProducto {
    private:
        int cantidadProducto;
        EstadoEnvio estado;
        Compra* compra;
        Producto* producto;
    public:
        CompraProducto(int, Compra*, Producto*);
        ~CompraProducto() = default;

        int getCantidadProducto();
        EstadoEnvio getEstadoEnvio();
        Compra* getCompra();
        Producto* getProducto();

        void setEnviado();
};

#include "producto.h"
#include "compra.h"

#endif