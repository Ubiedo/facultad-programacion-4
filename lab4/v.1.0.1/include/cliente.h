#ifndef CLIENTE
#define CLIENTE

#include "usuario.h"
#include "dataCliente.h"

using namespace std;

class Cliente: public Usuario {
    private:
        string calle, ciudad;
        int nroPuerta;
    public:
        Cliente(DataCliente);
        ~Cliente() = default;
        
        string getCalle();
        int getNroPuerta();
        string getCiudad();
        
        string toString();

        void setCalle(string);
        void setNroPuerta(int);
        void setCiudad(string);
};

#endif