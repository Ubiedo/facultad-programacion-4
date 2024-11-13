#ifndef DATAPRODUCTO
#define DATAPRODUCTO

#include "enumCategoria.h"

#include <string>
using namespace std;

class DataProducto {
    private:
        string nickname, nombre, descripcion;
        Categoria categoria;
        int stock;
        float precio;
    public:
        DataProducto(string nickname, string nombre, string descripcion, Categoria categoria, int stock, float precio);
        ~DataProducto() = default;

        string getNickname();
        string getNombre();
        string getDescripcion();
        Categoria getCategoria();
        int getStock();
        float getPrecio();
};

#endif