#ifndef CTRLPROMOPROD
#define CTRLPROMOPROD

#include "iPromoProd.h"
#include "ctrlUsuarios.h"
#include "promocion.h"
#include "promoProducto.h"
#include "producto.h"
#include "compraProducto.h"
#include "compra.h"
#include "dataNotificacion.h"

#include <map>
#include <vector>
#include <string>
using namespace std;

class CtrlPromoProd: public IPromoProd {
    private:
        static CtrlPromoProd* instancia; //Singleton
        int generadorCodigoProducto = 1;
        int generadorCodigoCompra = 1;
        map<string, Producto*> productos;
        map<string, Promocion*> promociones;
        CtrlPromoProd();
    public:
        ~CtrlPromoProd(); //CtrlPromoProd se encarga de la eliminación de Producto y Promocion
        static CtrlPromoProd* getInstancia();
        
        vector<DataProdBasica> listarProductos();
        Producto* findProducto(string);

        //Alta de Producto
        string crearProducto(string, string, string, Categoria, int, float);

        //Consultar Producto
        DataProdConsulta consultarProducto(string);

        //Dejar Comentario
        vector<DataComentario> comentariosDeProducto(string);

        //Crear Promocion
        vector<string> nombrePromociones();
        string crearPromocion(string, vector<DataProdCantidad>, string, string, float, DataFecha);

        //Consultar Promocion
        vector<DataPromoConsulta> listarPromoVigentes(DataFecha);
        DataVendedor infoVendedorPromo(string);
        vector<DataProdPromo> infoProductosPromo(string);

        //Realizar Compra
        vector<DataProdCompra> listarProductosDisponibles();
        DataCompra getDetallesCompra(vector<DataProdCantidad>, DataFecha);
        string realizarCompra(string, vector<DataProdCantidad>, DataFecha);

        //Enviar Producto
        vector<DataCompraPendiente> comprasPendientesProducto(string);
        string marcarComoEnviado(string, string);
};

#endif