#ifndef PROMOCION
#define PROMOCION

#include "dataFecha.h"
#include "dataProdPromo.h"
#include "dataPromoConsulta.h"
#include "dataProdCantidad.h"

#include <map>
#include <vector>
#include <string>
using namespace std;

class Vendedor;
class PromoProducto;

class Promocion {
    private:
        string nombre, descripcion; //Nombre la identifica
        float descuento;
        DataFecha vencimiento;
        Vendedor* vendedor;
        map<string, PromoProducto*> productos; //Almacena PromoProductos con la key del código del producto
    public:
        Promocion(Vendedor*, string, string, float, DataFecha);
        ~Promocion(); //Promocion es responsable de la eliminación de sus PromoProducto

        string getNombre();
        string getDescripcion();
        float getDescuento();
        DataFecha getVencimiento();
        Vendedor* getVendedor();
        DataPromoConsulta getDataPromoConsulta();

        void agregarPP(PromoProducto*, string); //Requerida por CtrlPromoProd para Crear Promocion
        bool esVigente(DataFecha); //Requerida por Producto para sinPromoVigente
        vector<DataProdPromo> infoProductos(); //Requerida por CtrlPromoProd para Consultar Promocion
        bool cumpleRequisitos(vector<DataProdCantidad>); //Requerida por CtrlPromoProd para Realizar Compra
};

#include "vendedor.h"
#include "promoProducto.h"

#endif