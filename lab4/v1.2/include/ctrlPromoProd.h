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
        int generadorCodigoProducto = 1;
        map<string, Producto*> productos;
        CtrlPromoProd();
    public:
        ~CtrlPromoProd();
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

        //Requeridas por CtrlUsuarios
        Producto* findProducto(string);
};

#endif