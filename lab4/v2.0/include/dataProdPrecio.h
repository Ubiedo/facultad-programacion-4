#ifndef DATAPRODPRECIO
#define DATAPRODPRECIO

#include <string>
using namespace std;

class DataProdPrecio {
    private:
        string codigo;
        string nombre;
        int cantidad;
        float descuento, subtotal;
    public:
        DataProdPrecio(string, string, int, float, float);
        ~DataProdPrecio() = default;

        string getCodigo();
        string getNombre();
        int getCantidad();
        float getDescuento();
        float getSubtotal();
};

#endif