#ifndef CTRLPROMOPROD
#define CTRLPROMOPROD

#include "iPromoProd.h"
#include "promocion.h"
#include "producto.h"

using namespace std;

class CtrlPromoProd: public IPromoProd {
    private:
        static CtrlPromoProd* instancia; //Singleton
        map<string, Promocion*> promociones;
        map<string, Producto*> productos;
        CtrlPromoProd();
    public:
        ~CtrlPromoProd();
        static CtrlPromoProd* getInstancia();

        vector<string> getNickClientes();
        vector<DataProducto> iniciarCompra(string clienteElegido);
        void agregarACompra(string codigoProducto, int cantidad);
        DataCompraFull getDetallesCompra();
        void confirmarCompra();
        vector<string> crearPromocion(DataPromocion dp);
};

#endif