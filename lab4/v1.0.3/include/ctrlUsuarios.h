#ifndef CTRLUSUARIOS
#define CTRLUSUARIOS

#include "iUsuarios.h"
#include "cliente.h"
#include "vendedor.h"

#include <map>
#include <vector>
#include <string>
using namespace std;

class CtrlUsuarios: public IUsuarios {
    private:
        static CtrlUsuarios* instancia; //Singleton
        map<string, Cliente*> clientes;
        map<string, Vendedor*> vendedores;
        CtrlUsuarios();
    public:
        ~CtrlUsuarios();
        static CtrlUsuarios* getInstancia();

        //Alta de Usuario
        string crearCliente(DataCliente);
        string crearVendedor(DataVendedor);

        //Listado de Usuarios
        vector<string> listarUsuarios();
        
        //Requeridas por CtrlPromoProd
        bool isEmptyVendedores();
        vector<string> nicknameVendedores();
        Vendedor* getVendedor(string);

        // Suscribirse a Notificaciones
        set<string> getVendedoresNoSuscritos(string cliente);
        void suscribirAlVendedor(string cliente, string vendedor);

        // Consulta a Notificaciones
        set<DataNotificacion> getNotificacionesDeCliente(string cliente);
        void vaciarNotificaciones(string cliente);

        // Eliminar suscripciones
        set<string> getSuscripcionesDeCliente(string cliente);
        void eliminarSuscripcionClienteAVendedor(string cliente, string vendedor);
};

#endif