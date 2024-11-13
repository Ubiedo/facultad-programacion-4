#ifndef CTRLUSUARIOS
#define CTRLUSUARIOS

#include "iUsuarios.h"
#include "dataComentario.h"
#include "cliente.h"
#include "vendedor.h"

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

        string crearCliente(DataCliente);
        string crearVendedor(DataVendedor);
        vector<string> listarUsuarios();
        vector<DataComentario> seleccionarUsuario(string usuarioElegidoNombre);
        void eliminarComentario(string comentarioId);
        
        vector<DataNotificacion> getNotificacionesDeCliente(string cliente);
        void vaciarNotificaciones();
        void seleccionarCliente(string nickname);
        vector<string> getVendedoresNoSuscritos();
        void suscribirAlVendedor(string nickname);
        void suscripcionesRealizadas();
        vector<string> getSuscripcionesDeCliente(string cliente);
        void eliminarSuscripcionClienteAVendedor(string vendedorName);
};

#endif