#ifndef DATAPRODBASICA
#define DATAPRODBASICA

#include <string>

using namespace std;

class DataProdBasica {
    private:
        string id;
        string nombre;
    public:
        DataProdBasica(string id, string nombre);
        ~DataProdBasica() = default;

        string getId();
        string getNombre();
};

#endif