#ifndef VENDEDOR
#define VENDEDOR

#include "usuario.h"
#include "subject.h"
#include "producto.h"
#include "dataVendedor.h"
#include "dataProdBasica.h"

#include <map>
#include <set>
#include <string>
using namespace std;

class Promocion;

class Vendedor: public Usuario, public Subject {
    private:
        string nroRut;
        map<string, Producto*> productos;
        map<string, Promocion*> promociones;
    public:
        Vendedor(DataVendedor);
        ~Vendedor();
        
        string getNroRut();

        string toString(); //Requerida por CtrlUsuarios para Listado de Usuarios
        void agregarProducto(Producto*); //Requerida por CtrlPromoProd para Alta de Producto
        bool tieneProductoDisponible(DataFecha); //Requerida por CtrlUsuarios para Crear Promocion
        vector<DataProdBasica> productosDisponibles(DataFecha); //Requerida por CtrlUsuarios para Crear Promocion
        void agregarPromocion(Promocion*); //Requerida por CtrlPromoProd para Crear Promocion
        DataVendedor getDataVendedor(); //Requerida por CtrlUsuarios para Expediente Usuario
        set<string> getNombresDeProductosEnVenta(); //Requerida por CtrlUsuarios para Expediente Usuario
        set<string> getNombresDePromocionesVigente(); //Requerida por CtrlUsuarios para Expediente Usuario
};

#include "promocion.h"

#endif