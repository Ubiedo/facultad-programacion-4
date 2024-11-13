#ifndef COMPRAPRODUCTO
#define COMPRAPRODUCTO

#include "enumEstadoEnvio.h"
#include "dataProdExp.h"

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

        void marcarComoEnviado(); //Requerida por Producto para marcarComoEnviado
        DataProdExp getDataProdExp(); //Requerida por Compra para getDataCompraExp;
};

#include "producto.h"
#include "compra.h"

#endif