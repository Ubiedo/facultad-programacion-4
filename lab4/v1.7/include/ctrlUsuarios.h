#ifndef CTRLUSUARIOS
#define CTRLUSUARIOS

#include "iUsuarios.h"
#include "vendedor.h"
#include "cliente.h"
#include "ctrlPromoProd.h"

#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;

class CtrlUsuarios: public IUsuarios {
    private:
        static CtrlUsuarios* instancia; //Singleton
        int generadorCodigoComentario = 1;
        map<string, Cliente*> clientes;
        map<string, Vendedor*> vendedores;
        CtrlUsuarios();
    public:
        ~CtrlUsuarios();
        static CtrlUsuarios* getInstancia();

        //Alta de Usuario
        string crearCliente(DataCliente);
        string crearVendedor(DataVendedor);

        //Alta de Producto
        bool isEmptyVendedores();
        vector<string> nicknameVendedores();

        //Listado de Usuarios
        vector<string> listarUsuarios();

        //Dejar Comentario
        vector<string> nicknameUsuarios();
        void crearComentario(DataComentario);

        //Eliminar Comentario
        bool isEmptyComentarios();
        vector<string> usuariosConComentarios();
        vector<DataCmtBasica> comentariosDeUsuario(string);
        void eliminarComentario(string nickname, string codigo);

        //Crear Promocion
        vector<string> vendedoresConProductoDisponible(DataFecha);
        vector<DataProdBasica> productosDisponiblesVendedor(string, DataFecha);
        
        //Suscribirse a Notificaciones
        vector<string> clientesParaSuscripcion();
        vector<string> vendedoresParaSuscripcion(string);
        void realizarSuscripciones(string, vector<string>);

        //Consultar Notificaciones
        vector<string> nicknameClientes();
        vector<string> notificacionesCliente(string);

        //Eliminar Suscripciones
        vector<string> clientesConSuscripcion();
        vector<string> suscripcionesDeCliente(string);
        void eliminarSuscripciones(string, vector<string>);

        //Expediente de Usuario
        vector<string> getUsuarios();
        bool esCliente(string);
        DataCliente getDataCliente(string);
        vector<DataCompra> getCompraExpediente(string);
        DataVendedor getDataVendedor(string);
        set<string> getNombresDeProductosEnVentaDeVendedor(string);
        set<string> getNombresDePromocionesVigenteDeVendedor(string);
        
        //Requeridas por CtrlPromoProd
        Vendedor* findVendedor(string);
        Cliente* findCliente(string);
};

#endif