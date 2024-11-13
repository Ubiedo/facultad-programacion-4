#ifndef IUSUARIOS
#define IUSUARIOS

#include "dataCliente.h"
#include "dataVendedor.h"
#include "dataComentario.h"
#include "dataNotificacion.h"

#include <vector>

using namespace std;

class IUsuarios {
    public:
        // IUsuarios();
        virtual ~IUsuarios() = 0;

        virtual string crearCliente(DataCliente dc) = 0;
        virtual string crearVendedor(DataVendedor dv) = 0;
        virtual vector<string> listarUsuarios() = 0;
        virtual vector<DataComentario> seleccionarUsuario(string usuarioElegidoNombre) = 0;
        virtual void eliminarComentario(string comentarioId) = 0;

        virtual vector<DataNotificacion> getNotificacionesDeCliente(string cliente) = 0;
        virtual void vaciarNotificaciones() = 0;
        virtual void seleccionarCliente(string nickname) = 0;
        virtual vector<string> getVendedoresNoSuscritos() = 0;
        virtual void suscribirAlVendedor(string nickname) = 0;
        virtual void suscripcionesRealizadas() = 0;
        virtual vector<string> getSuscripcionesDeCliente(string cliente) = 0;
        virtual void eliminarSuscripcionClienteAVendedor(string vendedorName) = 0;
};

#endif