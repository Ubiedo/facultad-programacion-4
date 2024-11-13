#ifndef NOTICLIENTE
#define NOTICLIENTE

#include "dataNotificacion.h"
#include "dataProducto.h"
#include "producto.h"

#include <string>

using namespace std;

class NotiCliente {
    private:
        string nickVendedor, nombPromo, identificador;
        set<Producto*> productos; // no es vacio porque son los prod de una promo y la promo tiene almenos un prod, lo comento nomas
    public:
        NotiCliente(string nickVendedor, string nombPromo, string identificador, set<Producto*> productos);
        ~NotiCliente();

        // void setProd(Producto prod); // que hace? ( esta en el DCD )
        DataNotificacion getDataNotificacion();
        
        string getNickVendedor();
        string getNombPromo();
        string getIdentificador();
        set<Producto*> getProductos();
        set<DataProducto> getDataProductos();
};

#endif