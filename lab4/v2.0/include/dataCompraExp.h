#ifndef DATACOMPRAEXP
#define DATACOMPRAEXP

#include "dataFecha.h"
#include "dataProdExp.h"

#include <vector>
#include <string>
using namespace std;

class DataCompraExp {
    private:
        string codigo;
        float monto;
        DataFecha fecha;
        vector<DataProdExp> productos;
    public:
        DataCompraExp(string, float, DataFecha, vector<DataProdExp>);
        ~DataCompraExp() = default;

        string getCodigo();
        float getMonto();
        DataFecha getFecha();
        vector<DataProdExp> getProductos();
};

#endif