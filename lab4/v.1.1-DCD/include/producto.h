#ifndef PRODUCTO
#define PRODUCTO

#include "dataProducto.h"
#include "dataPromoProd.h"
#include "enumCategoria.h"
#include "promoProducto.h"

#include <vector>

using namespace std;

class Producto {
    private:
        int id;
        string nombre, descripcion;
        Categoria categoria;
        int stock;
        float precio;
        vector<PromoProducto*> promosProducto;
    public:
        Producto(int id, string nombre, string descripcion, Categoria categoria, int stock, float precio);
        ~Producto() = default;

        int getId();
        string getNombre();
        string getDescripcion();
        Categoria getCategoria();
        int getStock();
        float getPrecio();
        vector<PromoProducto*> getPromosProducto();
        void addToPromosProducto(PromoProducto nuevaPromoProducto); // esto va o se hace directo tipo object.promosProducto.add(nuevaPromoProducto) por vector???

        void setStock(int);
        void setPrecio(float);

        DataProducto getDataProducto();
        float promoVigente();
        DataPromoProd getInfoPromo(int cant);
        void reducirStockEnCantidad(int cant);
};

#endif