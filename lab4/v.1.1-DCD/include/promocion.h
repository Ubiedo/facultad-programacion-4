#ifndef PROMOCION
#define PROMOCION

#include "dataFecha.h"
#include "promoProducto.h"

#include <string>

using namespace std;

class Promocion {
    private:
        string identificador, nombre, description;
        DataFecha vencimiento;
        int cantProductos;
        float descuento;
        vector<PromoProducto*> promoProductos; // no puede ser vacio
    public:
        Promocion(string identificador, string nombre, string description, DataFecha vencimiento, int cantProductos, float descuento, vector<PromoProducto*> promoProductos);
        ~Promocion() = default;

        string getIdentificador();
        string getNombre();
        string getDescripcion();
        int getCantProductos();
        float getDescuento();
        vector<PromoProducto*> getPromoProductos();

        void agregarProductoEnCantidad(int cant);
        void asociarProdsNoti();
};

#endif