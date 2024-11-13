#ifndef PRODUCTO
#define PRODUCTO

#include "comentario.h"
#include "promoProducto.h"
#include "compraProducto.h"
#include "dataProdBasica.h"
#include "dataProdConsulta.h"
#include "dataProdCompra.h"
#include "dataComentario.h"
#include "dataCompraPendiente.h"

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
        map<string, CompraProducto*> enviosPendientes;
        map<string, Comentario*> comentarios;
    public:
        Producto(Vendedor*, string, string, string, Categoria, int, float);
        ~Producto() = default;

        Vendedor* getVendedor();
        string getCodigo();
        string getNombre();
        string getDescripcion();
        Categoria getCategoria();
        int getStock();
        float getPrecio();

        DataProdBasica getDataProdBasica();
        DataProdConsulta getDataProdConsulta();
        DataProdCompra getDataProdCompra();

        vector<DataComentario> getComentarios(); //Requerida por CtrlPromoProd para Dejar Comentario
        Comentario* findComentario(string); //Requerida por CtrlUsuarios para Dejar Comentario
        void agregarComentario(Comentario*); //Requerida por CtrlUsuarios para Dejar Comentario
        void removerComentario(string); //Requerida por CtrlUsuarios para Eliminar Comentario

        bool sinPromoVigente(DataFecha); //Requerida por CtrlPromoProd para Crear Promocion
        void setPP(PromoProducto*); //Requerida por CtrlPromoProd para Crear Promocion

        string getNombrePromo(); //Requerida por CtrlPromoProd para Realizar Compra
        void agregarCP(CompraProducto*, string); //Requerida por CtrlPromoProd para Realizar Compra
        void disminuirStock(int); //Requerida por CtrlPromoProd para Realizar Compra

        bool tieneEnvioPendiente(); //Requerida por Producto para enviosPendientes
        vector<DataCompraPendiente> getComprasPendientes(); //Requerida por CtrlPromoProd para Enviar Producto
        string marcarComoEnviado(string); //Requerida por CtrlPromoProd para Enviar Producto
};

#include "vendedor.h"

#endif