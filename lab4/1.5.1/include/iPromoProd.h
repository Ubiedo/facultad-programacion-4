#ifndef IPROMOPROD
#define IPROMOPROD

#include "dataFecha.h"
#include "dataProducto.h"
#include "dataProdBasica.h"
#include "dataProdConsulta.h"
#include "dataProdCompra.h"
#include "dataCmtBasica.h"
#include "dataPromocion.h"
#include "dataPromoConsulta.h"
#include "dataPromoProducto.h"
#include "dataProdCompra.h"
#include "dataCompra.h"
#include "dataEnvioPendiente.h"

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

        //Crear Promocion
        virtual bool existeProductoDisponible(DataFecha) = 0;
        virtual vector<string> nombrePromociones() = 0;
        virtual void crearPromocion(DataPromocion) = 0;
        
        //Consultar Promocion
        virtual bool existePromoVigente(DataFecha) = 0;
        virtual vector<DataPromoConsulta> listarPromoVigentes(DataFecha) = 0;
        virtual string infoVendedorPromo(string) = 0;
        virtual vector<string> infoProductosPromo(string) = 0;

        //Realizar Compra
        virtual vector<DataProdCompra> listarProductosDisponibles() = 0;
        virtual DataCompra getDetallesCompra(vector<DataPromoProducto>, DataFecha) = 0;
        virtual void realizarCompra(string, vector<DataPromoProducto>, DataFecha, float) = 0;

        //Enviar Producto
        virtual bool hayEnviosPendientes() = 0;
        virtual vector<string> getVendedoresConEnviosPendientes() = 0;
        virtual vector<string> getProductosConEnviosPendientesDeVendedor(string) = 0;
        virtual vector<DataEnvioPendiente> getSolicitudesDeEnviosParaProducto(string, string) = 0;
        virtual void marcarComoEnviado(string, string, string, string) = 0;
};

#endif