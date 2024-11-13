#ifndef PRODUCTO
#define PRODUCTO

#include "vendedor.h"
#include "dataProducto.h"
#include "dataProdBasica.h"
#include "dataProdConsulta.h"

#include <string>
using namespace std;

class Vendedor;

class Producto {
    private:
        int id;
        Vendedor* vendedor;
        string nombre;
        string descripcion;
        Categoria categoria;
        int stock;
        float precio;
    public:
        Producto(int id, string nombre, string descripcion, Categoria categoria, int stock, float precio);
        ~Producto() = default;

        int getId();
        Vendedor* getVendedor();
        string getNombre();
        string getDescripcion();
        Categoria getCategoria();
        int getStock();
        float getPrecio();
        DataProdConsulta getDataProdConsulta();

        void setVendedor(Vendedor*);
        void setStock(int);
        void setPrecio(float);
};

#endif