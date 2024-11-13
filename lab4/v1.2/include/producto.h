#ifndef PRODUCTO
#define PRODUCTO

#include "comentario.h"
#include "dataProdConsulta.h"
#include "dataCmtBasica.h"

#include <map>
#include <vector>
#include <string>
using namespace std;

class Vendedor;

class Producto {
    private:
        string codigo;
        string nombre;
        string descripcion;
        Categoria categoria;
        int stock;
        float precio;
        Vendedor* vendedor;
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

        void setStock(int);
        void setPrecio(float);

        DataProdConsulta getDataProdConsulta(); //Requerida por CtrlPromoProd para Consultar Producto
        bool tieneComentarios(); //Requerida por CtrlPromoProd para Dejar Comentario
        Comentario* findComentario(string); //Requerida por CtrlUsuarios para Dejar Comentario
        void agregarComentario(Comentario*); //Requerida por CtrlUsuarios para Dejar Comentario
        vector<DataCmtBasica> getComentarios(); //Requerida por CtrlPromoProd para Dejar Comentario
        void removerComentario(string); //Requerida por CtrlUsuarios para Eliminar Comentario
};

#include "vendedor.h"

#endif