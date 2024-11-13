#ifndef VENDEDOR
#define VENDEDOR

#include "usuario.h"
#include "dataProdBasica.h"
#include "dataVendedor.h"
#include "iSubject.h"
#include "producto.h"
#include "promocion.h"

using namespace std;

class Vendedor: public Usuario, public ISubject{
    private:
        string nroRut;
        map<int, Producto*> productos;
        vector<Promocion*> promociones;
    public:
        Vendedor(DataVendedor dv);
        ~Vendedor() = default;

        string getNroRut();
        map<int, Producto*> getProductos();
        vector<Promocion*> getPromociones();

        void crearProducto(Producto prod);
        void crearPromocion(Promocion promo);

        vector<DataProductoBasica> getDataBasicaProductos();
        
};

#endif