#ifndef DATAPRODCONSULTA
#define DATAPRODCONSULTA

#include "enumCategoria.h"
#include <string>

using namespace std;

class DataProdConsulta {
    private:
        string vendedor;
        string descripcion;
        Categoria categoria;
        int stock;
        float precio;
    public:
        DataProdConsulta(string vendedor, string descripcion, Categoria categoria, int stock, float precio);
        ~DataProdConsulta() = default;

        string getVendedor();
        string getDescripcion();
        Categoria getCategoria();
        int getStock();
        float getPrecio();
};

#endif