#ifndef CLIENTE
#define CLIENTE

#include "usuario.h"
#include "dataCliente.h"

#include <string>
using namespace std;

class Cliente: public Usuario {
    private:
        string calle, ciudad;
        int nroPuerta;
    public:
        Cliente(DataCliente);
        ~Cliente();
        
        string getCalle();
        int getNroPuerta();
        string getCiudad();
        
        void setCalle(string);
        void setNroPuerta(int);
        void setCiudad(string);

        string toString(); //Requerida por CtrlUsuarios para Listado de Usuarios
};

#endif