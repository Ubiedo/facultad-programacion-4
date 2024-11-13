#ifndef COMPRA
#define COMPRA

#include "dataFecha.h"
#include "dataCompraExp.h"
#include "dataProdExp.h"

#include <map>
#include <vector>
#include <string>
using namespace std;

class Cliente;
class CompraProducto;

class Compra {
    private:
        string codigo;
        DataFecha fecha;
        float monto;
        Cliente* cliente;
        map<string, CompraProducto*> productos;
    public:
        Compra(string, DataFecha, float, Cliente*);
        ~Compra(); //Compra se encarga de la eliminación de sus CompraProducto

        string getCodigo();
        DataFecha getFecha();
        float getMonto();
        Cliente* getCliente();

        void agregarCP(CompraProducto*, string);
        DataCompraExp getDataCompraExp();
};

#include "cliente.h"
#include "compraProducto.h"

#endif