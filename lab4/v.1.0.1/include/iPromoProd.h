#ifndef IPROMOPROD
#define IPROMOPROD

#include "dataProducto.h"
#include "dataProdBasica.h"
#include "dataProdConsulta.h"
#include "dataComentario.h"

#include <vector>

using namespace std;

class IPromoProd {
    public:
        IPromoProd();
        virtual ~IPromoProd() = 0;

        //Alta de Producto
        virtual vector<string> listarVendedores() = 0;
        virtual void agregarProducto(string, DataProd) = 0;

        //Consultar Producto
        virtual vector<DataProdBasica> listarProductos() = 0;
        virtual DataProdConsulta consultarProducto(string) = 0;

        //Dejar Comentario
        virtual vector<string> listarUsuarios() = 0;
        //listarProductos
        virtual vector<DataComentario> comentariosDeProducto(string idProducto) = 0;
        virtual void responderComentario(string nickname, string idProducto, string idComentario, string texto) = 0;
        virtual void comentarProducto(string nickname, string idProducto, string texto) = 0;

        //Eliminar Comentario
        //listarUsuarios
        virtual vector<DataComentario> comentariosDeUsuario(string) = 0;
        virtual void eliminarComentario(string) = 0;
};

#endif