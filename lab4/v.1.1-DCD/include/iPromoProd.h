#ifndef IPROMOPROD
#define IPROMOPROD

#include "dataProducto.h"
#include "dataCompraFull.h"

#include <vector>

using namespace std;

class IPromoProdCompra {
    public:
        // IPromoProd();
        virtual ~IPromoProd() = 0;

        virtual vector<string> getNickClientes() = 0;
        virtual vector<DataProducto> iniciarCompra(string clienteElegido) = 0;
        virtual void agregarACompra(string codigoProducto, int cantidad) = 0;
        virtual DataCompraFull getDetallesCompra() = 0;
        virtual void confirmarCompra() = 0;
        virtual vector<string> crearPromocion(DataPromocion dp) = 0;
};

#endif