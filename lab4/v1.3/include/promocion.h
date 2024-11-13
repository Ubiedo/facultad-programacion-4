#ifndef PROMOCION
#define PROMOCION

#include "dataFecha.h"
#include "dataPromoConsulta.h"
#include "dataProductosPromo.h"

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
        Promocion(Vendedor* vendedor, string nombre, string descripcion, float descuento, DataFecha vencimiento);
        ~Promocion(); //Promocion es responsable de la eliminación de PromoProducto

        string getNombre();
        string getDescripcion();
        float getDescuento();
        DataFecha getVencimiento();
        Vendedor* getVendedor();

        bool esVigente(DataFecha); //Requerida por PromoProducto para esVigente
        void agregarPP(PromoProducto*, string); //Requerida por CtrlPromoProd para Crear Promocion
        DataPromoConsulta getDataPromoConsulta(); //Requerida por CtrlPromoProd para Consultar Promocion
        vector<DataProductosPromo> infoProductos(); //Requerida por CtrlPromoProd para Consultar Promocion
};

#include "vendedor.h"
#include "promoProducto.h"

#endif