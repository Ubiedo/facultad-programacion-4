#ifndef DATACLIENTE
#define DATACLIENTE

#include "dataUsuario.h"

#include <string>
using namespace std;

class DataCliente: public DataUsuario {
    private:
        string calle, ciudad, nroPuerta;
    public:
        DataCliente(string nickname, string contrasena, DataFecha fechaNacimiento, string calle, string nroPuerta, string ciudad);
        ~DataCliente() = default;
        
        string getCalle();
        string getNroPuerta();
        string getCiudad();
};

#endif