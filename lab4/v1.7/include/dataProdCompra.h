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
        DataProdCompra(string codigo, string nombre, int stock);
        ~DataProdCompra() = default;

        string getCodigo();
        string getNombre();
        int getStock();
};

#endif