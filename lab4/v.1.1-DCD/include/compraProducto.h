#ifndef COMPRAPRODUCTO
#define COMPRAPRODUCTO

#include "enumEstadoEnvio.h"
#include "dataProducto.h"
#include "dataCP.h"
#include "dataPromoProd.h"
#include "producto.h"


class CompraProducto {
    private:
        int cantProducto; // > 0
        EstadoEnvio estado;
        Producto* producto;
    public:
        CompraProducto(int cantProducto, EstadoEnvio estado);
        ~CompraProducto() = default;

        int getCantProducto();
        EstadoEnvio getEstado();
        Producto* getProducto();

        void setEstado(EstadoEnvio nuevoEstado);
        
        void asociarProducto(Producto prod);
        DataProducto getDataProducto();
        DataCP evaluar();
        DataPromoProd getInfoPromo();
        void reducirStock();
};

#endif