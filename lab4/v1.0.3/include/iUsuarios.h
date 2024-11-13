#ifndef IUSUARIOS
#define IUSUARIOS

#include "dataCliente.h"
#include "dataVendedor.h"
#include "dataProducto.h"
#include "dataNotificacion.h"

#include <vector>
#include <set>
using namespace std;

class IUsuarios {
    public:
        IUsuarios();
        virtual ~IUsuarios() = 0;

        //Alta de Usuario
        virtual string crearCliente(DataCliente) = 0;
        virtual string crearVendedor(DataVendedor) = 0;

        //Listado de Usuarios
        virtual vector<string> listarUsuarios() = 0;

        // Suscribirse a Notificaciones
        virtual set<string> getVendedoresNoSuscritos(string cliente) = 0;
        virtual void suscribirAlVendedor(string cliente, string vendedor) = 0;

        // Consulta a Notificaciones
        virtual set<DataNotificacion> getNotificacionesDeCliente(string cliente) = 0;
        virtual void vaciarNotificaciones(string cliente) = 0;

        // Eliminar suscripciones
        virtual set<string> getSuscripcionesDeCliente(string cliente) = 0;
        virtual void eliminarSuscripcionClienteAVendedor(string cliente, string vendedor) = 0;
};

#endif