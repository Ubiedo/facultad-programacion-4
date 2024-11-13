#ifndef IPROMOPROD
#define IPROMOPROD

#include "dataProducto.h"
#include "dataProdBasica.h"
#include "dataProdConsulta.h"
#include "dataCmtBasica.h"

#include <vector>
#include <string>
using namespace std;

class IPromoProd {
    public:
        IPromoProd();
        virtual ~IPromoProd() = 0;

        //Alta de Producto
        virtual void crearProducto(DataProducto) = 0;

        //Consultar Producto
        virtual bool isEmptyProductos() = 0;
        virtual vector<DataProdBasica> listarProductos() = 0;
        virtual DataProdConsulta consultarProducto(string) = 0;

        //Dejar Comentario
        //listarProductos() ya implementada en Consultar Producto
        virtual vector<DataCmtBasica> comentariosDeProducto(string) = 0;
        virtual bool productoTieneComentarios(string) = 0;
};

#endif