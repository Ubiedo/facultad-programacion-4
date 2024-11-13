#ifndef CTRLPROMOPROD
#define CTRLPROMOPROD

#include "iPromoProd.h"
#include "ctrlUsuarios.h"
#include "promocion.h"
#include "promoProducto.h"
#include "producto.h"
#include "compraProducto.h"
#include "compra.h"

#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;

class CtrlPromoProd: public IPromoProd {
    private:
        static CtrlPromoProd* instancia; //Singleton
        int generadorCodigoProducto = 1;
        int generadorCodigoCompra = 1;
        map<string, Producto*> productos;
        map<string, Promocion*> promociones;
        map<string, set<CompraProducto*> > enviosPendientes; // (vendedor Nombre, sus comprasProductos)
        // map<string, CompraProducto*> (Prd#Cmp#, compraProducto)
        CtrlPromoProd();
    public:
        ~CtrlPromoProd(); //CtrlPromoProd se encarga de la eliminación de Producto y Promocion
        static CtrlPromoProd* getInstancia();
        
        //Alta de Producto
        void crearProducto(DataProducto);

        //Consultar Producto
        bool isEmptyProductos();
        vector<DataProdBasica> listarProductos();
        DataProdConsulta consultarProducto(string);

        //Dejar Comentario
        vector<DataCmtBasica> comentariosDeProducto(string);
        bool productoTieneComentarios(string);

        //Crear Promocion
        bool existeProductoDisponible(DataFecha);
        vector<string> nombrePromociones();
        void crearPromocion(DataPromocion);

        //ConsultarPromocion
        bool existePromoVigente(DataFecha);
        vector<DataPromoConsulta> listarPromoVigentes(DataFecha);
        string infoVendedorPromo(string);
        vector<string> infoProductosPromo(string);

        //Realizar Compra
        vector<DataProdCompra> listarProductosDisponibles();
        DataCompra getDetallesCompra(vector<DataPromoProducto>, DataFecha);
        void realizarCompra(string, vector<DataPromoProducto>, DataFecha, float);

        //Enviar Producto
        bool noHayEnviosPendientes();
        vector<string> getVendedoresConEnviosPendientes();
        set<string> getProductosConEnviosPendientesDeVendedor(string);
        vector<DataEnvioPendiente> getSolicitudesDeEnviosParaProducto(string, string);
        void marcarComoEnviado(string, string, string);

        //Requeridas por CtrlUsuarios
        Producto* findProducto(string);
};

#endif