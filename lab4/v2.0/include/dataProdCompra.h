#ifndef DATAPRODCOMPRA
#define DATAPRODCOMPRA

#include <string>
using namespace std;

class DataProdCompra {
    private:
        string codigo;
        string nombre;
        int stock;
    public:
        DataProdCompra(string, string, int);
        ~DataProdCompra() = default;

        string getCodigo();
        string getNombre();
        int getStock();
};

#endif