#ifndef IPROMOPROD
#define IPROMOPROD

#include "dataFecha.h"
#include "enumCategoria.h"
#include "dataVendedor.h"
#include "dataProdBasica.h"
#include "dataProdConsulta.h"
#include "dataProdPromo.h"
#include "dataProdCompra.h"
#include "dataComentario.h"
#include "dataPromoConsulta.h"
#include "dataProdCantidad.h"
#include "dataProdCompra.h"
#include "dataCompra.h"
#include "dataCompraPendiente.h"

#include <vector>
#include <string>
using namespace std;

class IPromoProd {
    public:
        IPromoProd();
        virtual ~IPromoProd() = 0;

        //Alta de Producto
        virtual string crearProducto(string, string, string, Categoria, int, float) = 0;

        //Consultar Producto
        virtual vector<DataProdBasica> listarProductos() = 0;
        virtual DataProdConsulta consultarProducto(string) = 0;

        //Dejar Comentario
        virtual vector<DataComentario> comentariosDeProducto(string) = 0;

        //Crear Promocion
        virtual vector<string> nombrePromociones() = 0;
        virtual string crearPromocion(string, vector<DataProdCantidad>, string, string, float, DataFecha) = 0;
        
        //Consultar Promocion
        virtual vector<DataPromoConsulta> listarPromoVigentes(DataFecha) = 0;
        virtual DataVendedor infoVendedorPromo(string) = 0;
        virtual vector<DataProdPromo> infoProductosPromo(string) = 0;

        //Realizar Compra
        virtual vector<DataProdCompra> listarProductosDisponibles() = 0;
        virtual DataCompra getDetallesCompra(vector<DataProdCantidad>, DataFecha) = 0;
        virtual string realizarCompra(string, vector<DataProdCantidad>, DataFecha) = 0;

        //Enviar Producto
        virtual vector<DataCompraPendiente> comprasPendientesProducto(string) = 0;
        virtual string marcarComoEnviado(string, string) = 0;
};

#endif