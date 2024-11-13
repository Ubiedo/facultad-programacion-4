#ifndef VENDEDOR
#define VENDEDOR

#include "usuario.h"
#include "producto.h"
#include "dataVendedor.h"

#include <map>
#include <string>
using namespace std;

class Vendedor: public Usuario {
    private:
        string nroRut;
        map<string, Producto*> productos;
    public:
        Vendedor(DataVendedor);
        ~Vendedor();
        
        string getNroRut();
        void setNroRut(string);

        string toString(); //Requerida por CtrlUsuarios para Listado de Usuarios
        void agregarProducto(Producto*); //Requerida por CtrlPromoProd para Alta de Producto
};

#endif