#ifndef CTRLPROMOPROD
#define CTRLPROMOPROD

#include "iPromoProd.h"
#include "ctrlUsuarios.h"
#include "producto.h"

#include <map>
#include <vector>
#include <string>
using namespace std;

class CtrlPromoProd: public IPromoProd {
    private:
        static CtrlPromoProd* instancia; //Singleton
        map<string, Producto*> productos;
        CtrlPromoProd();
    public:
        ~CtrlPromoProd();
        static CtrlPromoProd* getInstancia();
        
        //Alta de Producto
        bool isEmptyVendedores();
        vector<string> nicknameVendedores();
        void crearProducto(string, DataProducto);

        //Consultar Producto
        bool isEmptyProductos();
        vector<DataProdBasica> listarProductos();
        DataProdConsulta consultarProducto(string);

        /* Proximo a implementar
        //Dejar Comentario
        vector<string> listarUsuarios();
        //listarProductos
        vector<DataComentario> comentariosDeProducto(string idProducto);
        void responderComentario(string nickname, string idProducto, string idComentario, string texto);
        void comentarProducto(string nickname, string idProducto, string texto);

        //Eliminar Comentario
        //listarUsuarios
        vector<DataComentario> comentariosDeUsuario(string);
        void eliminarComentario(string);
        */
};

#endif