#ifndef DTDATAPROMOCION
#define DTDATAPROMOCION

#include <iostream>
#include "DTFecha.h"

using namespace std;

class DTDataPromocion {
    private:
        string nombre, descripcion;
        DTFecha vencimiento;
        float descuento;
    public:
        DTDataPromocion(string nombre, string descripcion, DataFecha vencimiento, float descuento);
        ~DTDataPromocion() = default;
        
        string getNombre();
        string getDescripcion();
        DTFecha getVencimiento();
        float getDescuento();
};

#endif