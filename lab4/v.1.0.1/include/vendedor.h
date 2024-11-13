#ifndef VENDEDOR
#define VENDEDOR

#include "usuario.h"
#include "dataVendedor.h"

using namespace std;

class Vendedor: public Usuario {
    private:
        string nroRut;
    public:
        Vendedor(DataVendedor);
        ~Vendedor() = default;
        
        string getNroRut();

        string toString();
        
        void setNroRut(string);
};

#endif