#ifndef VENDEDOR
#define VENDEDOR

#include "usuario.h"
#include "subject.h"
#include "producto.h"
#include "dataProducto.h"
#include "dataVendedor.h"
#include "dataProdBasica.h"

#include <map>
#include <string>
using namespace std;

class Promocion;

class Vendedor: public Usuario, public Subject {
    private:
        string nroRut;
        map<string, Producto*> productos;
        map<string, Promocion*> promociones;
    public:
        Vendedor(string, string, DataFecha, string);
        ~Vendedor(); //Vendedor se encarga de la eliminación de sus comentarios
        
        string getNroRut();
        DataVendedor getDataVendedor();

        void agregarProducto(Producto*); //Requerida por CtrlPromoProd para Alta de Producto
        void agregarPromocion(Promocion*); //Requerida por CtrlPromoProd para Crear Promocion
        bool tieneProductoDisponible(DataFecha); //Requerida por CtrlUsuarios para Crear Promocion
        vector<DataProdBasica> productosDisponibles(DataFecha); //Requerida por CtrlUsuarios para Crear Promocion
        vector<DataProdBasica> enviosPendientes(); //Requerida por CtrlUsuarios para Enviar Producto
        vector<DataProducto> getProductos(); //Requerida por CtrlUsuarios para Expediente de Usuario
        vector<DataPromoConsulta> getPromosVigentes(DataFecha); //Requerida por CtrlUsuarios para Expediente de Usuario
};

#include "promocion.h"

#endif