#ifndef IUSUARIOS
#define IUSUARIOS

#include "dataFecha.h"
#include "dataCliente.h"
#include "dataVendedor.h"
#include "dataProdBasica.h"
#include "dataComentario.h"
#include "dataCmtBasica.h"
#include "dataCompra.h"

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

        //Alta de Producto
        virtual bool isEmptyVendedores() = 0;
        virtual vector<string> nicknameVendedores() = 0;

        //Dejar Comentario
        virtual vector<string> nicknameUsuarios() = 0;
        virtual void crearComentario(DataComentario) = 0;

        //Eliminar Comentario
        virtual bool isEmptyComentarios() = 0;
        virtual vector<string> usuariosConComentarios() = 0;
        virtual vector<DataCmtBasica> comentariosDeUsuario(string) = 0;
        virtual void eliminarComentario(string nickname, string codigo) = 0;

        //Crear Promocion
        virtual vector<string> vendedoresConProductoDisponible(DataFecha) = 0;
        virtual vector<DataProdBasica> productosDisponiblesVendedor(string, DataFecha) = 0;

        //Suscribirse a Notificaciones
        virtual vector<string> clientesParaSuscripcion() = 0;
        virtual vector<string> vendedoresParaSuscripcion(string) = 0;
        virtual void realizarSuscripciones(string, vector<string>) = 0;

        //Consultar Notificaciones
        virtual vector<string> nicknameClientes() = 0;
        virtual vector<string> notificacionesCliente(string) = 0;

        //Eliminar Suscripciones
        virtual vector<string> clientesConSuscripcion() = 0;
        virtual vector<string> suscripcionesDeCliente(string) = 0;
        virtual void eliminarSuscripciones(string, vector<string>) = 0;

        //Expediente Usuario
        virtual vector<string> getUsuarios() = 0;
        virtual bool esCliente(string) = 0;
        virtual DataCliente getDataCliente(string) = 0;
        virtual vector<DataCompra> getCompraExpediente(string) = 0;
        virtual DataVendedor getDataVendedor(string) = 0;
        virtual set<string> getNombresDeProductosEnVentaDeVendedor(string) = 0;
        virtual set<string> getNombresDePromocionesVigenteDeVendedor(string) = 0;
};

#endif