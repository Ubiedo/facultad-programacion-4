#ifndef COMPRA
#define COMPRA

#include "dataFecha.h"
#include "dataProducto.h"
#include "compraProducto.h"
#include "compraPromo.h"

#include <string>

using namespace std;

class Compra {
    private:
        string identificador;
        DataFecha fecha;
        float monto;
        vector<CompraProducto*> compraProductos;
        vector<CompraPromo*> compraPromos;
    public:
        Compra(string identificador, DataFecha fecha, float monto);
        ~Compra() = default;

        string getIdentificador();
        DataFecha getFecha();
        float getMonto();
        vector<CompraProducto*> getCompraProductos();
        vector<CompraPromo*> getCompraPromos();

        void agregarEnCompraEnCantidadDada(int cantidad);
        vector<DataProducto> getDataProductos();
        void reservarProductos();
};

#endif