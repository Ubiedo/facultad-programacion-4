#ifndef COMPRA
#define COMPRA

#include "dataFecha.h"

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
        Compra(string codigo, DataFecha fecha, float monto, Cliente* cliente);
        ~Compra();

        string getCodigo();
        DataFecha getFecha();
        float getMonto();

        void agregarCP(CompraProducto*, string);
        string getNickCliente();

        vector<string> getNicknameProductos();
};

#include "cliente.h"
#include "compraProducto.h"

#endif