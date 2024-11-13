#ifndef CTRLUSUARIOS
#define CTRLUSUARIOS

#include "iUsuarios.h"
#include "vendedor.h"
#include "cliente.h"
#include "ctrlPromoProd.h"
#include "fechaSistema.h"

#include <map>
#include <vector>
#include <string>
using namespace std;

class CtrlUsuarios: public IUsuarios {
    private:
        static CtrlUsuarios* instancia; //Singleton
        int generadorCodigoComentario = 1;
        map<string, Cliente*> clientes;
        map<string, Vendedor*> vendedores;
        CtrlUsuarios();
    public:
        ~CtrlUsuarios(); //CtrlUsuarios se encarga de la eliminación de clientes y vendedores
        static CtrlUsuarios* getInstancia();

        vector<string> nicknameUsuarios();
        vector<string> nicknameClientes();
        vector<string> nicknameVendedores();
        Cliente* findCliente(string);
        Vendedor* findVendedor(string);

        //Alta de Usuario
        string crearCliente(string, string, DataFecha, string, string, string);
        string crearVendedor(string, string, DataFecha, string);

        //Listado de Usuarios
        vector<DataCliente> listarClientes();
        vector<DataVendedor> listarVendedores();

        //Dejar Comentario
        string crearComentario(string, string, string, string, DataFecha);

        //Eliminar Comentario
        vector<string> usuariosConComentarios();
        vector<DataComentario> comentariosDeUsuario(string);
        string eliminarComentario(string, string);

        //Crear Promocion
        vector<string> vendedoresConProductoDisponible(DataFecha);
        vector<DataProdBasica> productosDisponiblesVendedor(string, DataFecha);
        
        //Suscribirse a Notificaciones
        vector<string> vendedoresParaSuscripcion(string);
        string realizarSuscripciones(string, vector<string>);

        //Consultar Notificaciones
        vector<DataNotificacion> notificacionesCliente(string);

        //Eliminar Suscripciones
        vector<string> suscripcionesDeCliente(string);
        string eliminarSuscripciones(string, vector<string>);

        //Enviar Producto
        vector<DataProdBasica> enviosPendientesVendedor(string);

        //Expediente de Usuario
        bool esCliente(string);
        DataCliente getDataCliente(string);
        DataVendedor getDataVendedor(string);
        vector<DataCompraExp> getCompraExpediente(string);
        vector<DataProducto> getProductosVendedor(string);
        vector<DataPromoConsulta> getPromosVendedor(string, DataFecha);
};

#endif