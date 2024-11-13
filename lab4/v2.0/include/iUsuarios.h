#ifndef IUSUARIOS
#define IUSUARIOS

#include "dataFecha.h"
#include "dataCliente.h"
#include "dataVendedor.h"
#include "dataProducto.h"
#include "dataProdBasica.h"
#include "dataPromoConsulta.h"
#include "dataComentario.h"
#include "dataNotificacion.h"
#include "dataCompraExp.h"

#include <vector>
#include <string>
using namespace std;

class IUsuarios {
    public:
        IUsuarios();
        virtual ~IUsuarios() = 0;

        virtual vector<string> nicknameUsuarios() = 0;
        virtual vector<string> nicknameClientes() = 0;
        virtual vector<string> nicknameVendedores() = 0;

        //Alta de Usuario
        virtual string crearCliente(string, string, DataFecha, string, string, string) = 0;
        virtual string crearVendedor(string, string, DataFecha, string) = 0;

        //Listado de Usuarios
        virtual vector<DataCliente> listarClientes() = 0;
        virtual vector<DataVendedor> listarVendedores() = 0;

        //Dejar Comentario
        virtual string crearComentario(string, string, string, string, DataFecha) = 0;

        //Eliminar Comentario
        virtual vector<string> usuariosConComentarios() = 0;
        virtual vector<DataComentario> comentariosDeUsuario(string) = 0;
        virtual string eliminarComentario(string, string) = 0;

        //Crear Promocion
        virtual vector<string> vendedoresConProductoDisponible(DataFecha) = 0;
        virtual vector<DataProdBasica> productosDisponiblesVendedor(string, DataFecha) = 0;

        //Suscribirse a Notificaciones
        virtual vector<string> vendedoresParaSuscripcion(string) = 0;
        virtual string realizarSuscripciones(string, vector<string>) = 0;

        //Consultar Notificaciones
        virtual vector<DataNotificacion> notificacionesCliente(string) = 0;

        //Eliminar Suscripciones
        virtual vector<string> suscripcionesDeCliente(string) = 0;
        virtual string eliminarSuscripciones(string, vector<string>) = 0;

        //Enviar Producto
        virtual vector<DataProdBasica> enviosPendientesVendedor(string) = 0;

        //Expediente de Usuario
        virtual bool esCliente(string) = 0;
        virtual DataCliente getDataCliente(string) = 0;
        virtual DataVendedor getDataVendedor(string) = 0;
        virtual vector<DataCompraExp> getCompraExpediente(string) = 0;
        virtual vector<DataProducto> getProductosVendedor(string) = 0;
        virtual vector<DataPromoConsulta> getPromosVendedor(string, DataFecha) = 0;
};

#endif