#ifndef DATAPROMOCION
#define DATAPROMOCION

#include "dataFecha.h"

#include <string>

using namespace std;

class DataPromocion {
    private:
        string nombre, descripcion;
        DataFecha vencimiento;
        float descuento;
    public:
        DataPromocion(string nombre, string descripcion, DataFecha vencimiento, float descuento);
        ~DataPromocion() = default;
        
        string getNombre();
        string getDescripcion();
        DataFecha getVencimiento();
        float getDescuento();
};

#endif