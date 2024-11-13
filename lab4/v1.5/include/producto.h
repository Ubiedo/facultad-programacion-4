#ifndef PRODUCTO
#define PRODUCTO

#include "comentario.h"
#include "promoProducto.h"
#include "compraProducto.h"
#include "dataProdBasica.h"
#include "dataProdConsulta.h"
#include "dataProdCompra.h"
#include "dataCmtBasica.h"

#include <map>
#include <vector>
#include <string>
using namespace std;

class Vendedor;

class Producto {
    private:
        string codigo, nombre, descripcion;
        Categoria categoria;
        int stock;
        float precio;
        Vendedor* vendedor;
        PromoProducto* promocion = NULL; //Almacena una única promoción a la vez
        map<string, CompraProducto*> compras;
        map<string, Comentario*> comentarios;
    public:
        Producto(Vendedor* vendedor, string codigo, string nombre, string descripcion, Categoria categoria, int stock, float precio);
        ~Producto() = default;

        Vendedor* getVendedor();
        string getCodigo();
        string getNombre();
        string getDescripcion();
        Categoria getCategoria();
        int getStock();
        float getPrecio();

        DataProdBasica getDataProdBasica(); //Requerida por CtrlPromoProd para Consultar Producto
        DataProdConsulta getDataProdConsulta(); //Requerida por CtrlPromoProd para Consultar Producto

        bool tieneComentarios(); //Requerida por CtrlPromoProd para Dejar Comentario
        Comentario* findComentario(string); //Requerida por CtrlUsuarios para Dejar Comentario
        void agregarComentario(Comentario*); //Requerida por CtrlUsuarios para Dejar Comentario
        vector<DataCmtBasica> getComentarios(); //Requerida por CtrlPromoProd para Dejar Comentario
        void removerComentario(string); //Requerida por CtrlUsuarios para Eliminar Comentario

        bool disponibleParaPromocion(DataFecha); //Requerida por CtrlPromoProd para Crear Promocion
        void setPP(PromoProducto*); //Requerida por CtrlPromoProd para Crear Promocion

        string toString(); //Requerida por promoProducto para infoProducto
        DataProdCompra getDataProdCompra(); //Requerida por CtrlPromoProd para Realizar Compra
        string getNombrePromo(); //Requerida por CtrlPromoProd para Realizar Compra
        void agregarCP(CompraProducto*, string); //Requerida por CtrlPromoProd para Realizar Compra
        void disminuirStock(int); //Requerida por CtrlPromoProd para Realizar Compra

};

#include "vendedor.h"

#endif