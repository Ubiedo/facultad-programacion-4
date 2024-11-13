#ifndef CTRLUSUARIOS
#define CTRLUSUARIOS

#include "iUsuarios.h"
#include "dataCliente.h"
#include "dataVendedor.h"
#include "cliente.h"
#include "vendedor.h"

#include <vector>
#include <map>

using namespace std;

class CtrlUsuarios: public IUsuarios {
    private:
        map<string, Cliente*> clientes;
        map<string, Vendedor*> vendedores;
    public:
        CtrlUsuarios() {};
        ~CtrlUsuarios() = default;

        //Pre-Condicion: No existe un usuario con el mismo nickname
        string crearCliente(DataCliente);
        string crearVendedor(DataVendedor);
        vector<string> listarUsuarios();

        void vaciarUsuarios();
};

#endif