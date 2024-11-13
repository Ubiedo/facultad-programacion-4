#ifndef IUSUARIOS
#define IUSUARIOS

#include "dataCliente.h"
#include "dataVendedor.h"

#include <vector>

using namespace std;

class IUsuarios {
    public:
        IUsuarios();
        virtual ~IUsuarios() = 0;

        virtual string crearCliente(DataCliente) = 0;
        virtual string crearVendedor(DataVendedor) = 0;
        virtual vector<string> listarUsuarios() = 0;

        virtual void vaciarUsuarios() = 0;
};

#endif