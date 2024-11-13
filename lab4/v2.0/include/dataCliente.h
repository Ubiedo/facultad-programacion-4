#ifndef DATACLIENTE
#define DATACLIENTE

#include "dataUsuario.h"

#include <string>
using namespace std;

class DataCliente: public DataUsuario {
    private:
        string calle, ciudad, nroPuerta;
    public:
        DataCliente(string, DataFecha, string, string, string);
        ~DataCliente() = default;
        
        string getCalle();
        string getNroPuerta();
        string getCiudad();
};

#endif