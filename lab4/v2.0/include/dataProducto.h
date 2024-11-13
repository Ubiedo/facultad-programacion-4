#ifndef DATAPRODUCTO
#define DATAPRODUCTO

#include "enumCategoria.h"

#include <string>
using namespace std;

class DataProducto {
    private:
        string codigo, nombre, descripcion;
        Categoria categoria;
        int stock;
        float precio;
    public:
        DataProducto(string, string, string, Categoria, int, float);
        ~DataProducto() = default;

        string getCodigo();
        string getNombre();
        string getDescripcion();
        Categoria getCategoria();
        int getStock();
        float getPrecio();
};

#endif