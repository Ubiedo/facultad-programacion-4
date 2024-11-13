#ifndef DATAPRODEXP
#define DATAPRODEXP

#include "enumCategoria.h"
#include "enumEstadoEnvio.h"

#include <string>
using namespace std;

class DataProdExp {
    private:
        string codigo, nombre, vendedor, descripcion;
        Categoria categoria;
        int cantidad;
        EstadoEnvio estado;
    public:
        DataProdExp(string, string, string, string, Categoria, int, EstadoEnvio);
        ~DataProdExp() = default;

        string getCodigo();
        string getNombre();
        string getVendedor();
        string getDescripcion();
        Categoria getCategoria();
        int getCantidad();
        EstadoEnvio getEstado();
};

#endif