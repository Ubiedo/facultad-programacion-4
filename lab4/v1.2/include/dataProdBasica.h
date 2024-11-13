#ifndef DATAPRODBASICA
#define DATAPRODBASICA

#include <string>
using namespace std;

class DataProdBasica {
    private:
        string codigo;
        string nombre;
    public:
        DataProdBasica(string codigo, string nombre);
        ~DataProdBasica() = default;

        string getCodigo();
        string getNombre();
};

#endif