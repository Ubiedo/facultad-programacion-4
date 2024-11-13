#ifndef DATACLIENTE
#define DATACLIENTE

#include "dataUsuario.h"

using namespace std;

class DataCliente: public DataUsuario {
    private:
        string calle, ciudad;
        int nroPuerta;
    public:
        DataCliente(string nickname, string contrasena, DataFecha fechaNacimiento, string calle, int nroPuerta, string ciudad);
        ~DataCliente() = default;
        
        string getCalle();
        int getNroPuerta();
        string getCiudad();
};

#endif