#ifndef VENDEDOR
#define VENDEDOR

#include "usuario.h"
#include "producto.h"
#include "dataVendedor.h"
#include "dataProdBasica.h"

#include <map>
#include <string>
using namespace std;

class Promocion;

class Vendedor: public Usuario {
    private:
        string nroRut;
        map<string, Producto*> productos;
        map<string, Promocion*> promociones;
    public:
        Vendedor(DataVendedor);
        ~Vendedor();
        
        string getNroRut();
        void setNroRut(string);

        string toString(); //Requerida por CtrlUsuarios para Listado de Usuarios
        void agregarProducto(Producto*); //Requerida por CtrlPromoProd para Alta de Producto
        bool tieneProductoDisponible(DataFecha); //Requerida por CtrlUsuarios para Crear Promocion
        vector<DataProdBasica> productosDisponibles(DataFecha); //Requerida por CtrlUsuarios para Crear Promocion
        void agregarPromocion(Promocion*); //Requerida por CtrlPromoProd para Crear Promocion
};

#include "promocion.h"

#endif