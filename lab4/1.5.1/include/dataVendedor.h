#ifndef DATAVENDEDOR
#define DATAVENDEDOR

#include "dataUsuario.h"

#include <string>
using namespace std;

class DataVendedor: public DataUsuario {
    private:
        string nroRut;
    public:
        DataVendedor(string nickname, string contrasena, DataFecha fechaNacimiento, string nroRut);
        ~DataVendedor() = default;
        
        string getNroRut();
};

#endif