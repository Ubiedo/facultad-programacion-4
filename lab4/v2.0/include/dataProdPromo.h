#ifndef DATAPRODPROMO
#define DATAPRODPROMO

#include "enumCategoria.h"

#include <string>
using namespace std;

class DataProdPromo {
    private:
        string nombre, descripcion;
        Categoria categoria;
        int stock, minimo;
        float precio;
    public:
        DataProdPromo(string, string, Categoria, int, float, int);
        ~DataProdPromo() = default;

        string getNombre();
        string getDescripcion();
        Categoria getCategoria();
        int getStock();
        float getPrecio();
        int getMinimo();
};

#endif