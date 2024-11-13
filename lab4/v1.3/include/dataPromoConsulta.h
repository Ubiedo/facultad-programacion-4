#ifndef DATAPROMOCONSULTA
#define DATAPROMOCONSULTA

#include "dataFecha.h"

#include <string>
using namespace std;

class DataPromoConsulta {
    private:
        string nombre, descripcion;
        float descuento;
        DataFecha vencimiento;
    public:
        DataPromoConsulta(string nombre, string descripcion, float descuento, DataFecha vencimiento);
        ~DataPromoConsulta() = default;

        string getNombre();
        string getDescripcion();
        float getDescuento();
        DataFecha getVencimiento();
};

#endif