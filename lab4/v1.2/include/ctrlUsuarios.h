#ifndef CTRLUSUARIOS
#define CTRLUSUARIOS

#include "iUsuarios.h"
#include "vendedor.h"
#include "cliente.h"
#include "ctrlPromoProd.h"

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
        
        //Requeridas por CtrlPromoProd
        Vendedor* findVendedor(string);
};

#endif