#ifndef DATACOMPRA
#define DATACOMPRA

#include "dataFecha.h"

#include <vector>
#include <string>
using namespace std;

class DataCompra {
    private:
        float monto;
        DataFecha fecha;
        vector<string> infoProductos;
    public:
        DataCompra(float monto, DataFecha fecha, vector<string>infoProductos);
        ~DataCompra() = default;

        float getMonto();
        DataFecha getFecha();
        vector<string> getInfoProductos();
};

#endif