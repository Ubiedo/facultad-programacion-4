#ifndef VENDEDOR
#define VENDEDOR

#include "usuario.h"
#include "producto.h"
#include "dataVendedor.h"
#include "dataProducto.h"
#include "iSubject.h"

#include <map>
#include <string>
using namespace std;

class Producto;

class Vendedor: public Usuario, public ISubject {
    private:
        string nroRut;
        map<int, Producto*> productos;
    public:
        Vendedor(DataVendedor);
        ~Vendedor() = default;
        
        string getNroRut();
        void setNroRut(string);
        string toString();

        //Requeridas por CtrlPromoProd
        int generarId();
        void agregarProducto(Producto*);

        //Suscripcion
        void notificar();
};

#endif