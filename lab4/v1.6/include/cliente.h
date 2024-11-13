#ifndef CLIENTE
#define CLIENTE

#include "usuario.h"
#include "iObserver.h"
#include "vendedor.h"
#include "dataCliente.h"

#include <map>
#include <vector>
#include <string>
using namespace std;

class Compra;

class Cliente: public Usuario, public IObserver {
    private:
        string calle, ciudad, nroPuerta;
        vector<string> notificaciones;
        map<string, Vendedor*> suscripciones;
        map<string, Compra*> compras;
    public:
        Cliente(DataCliente);
        ~Cliente();
        
        string getCalle();
        string getNroPuerta();
        string getCiudad();

        string toString(); //Requerida por CtrlUsuarios para Listado de Usuarios
        void notificar(string); //Requerida por IObserver
        bool estaSuscrito(string); //Requerida por CtrlUsuarios para Suscribirse a Notificaciones
        void suscribirse(Vendedor*); //Requerida por CtrlUsuarios para Suscribirse a Notificaiones
        vector<string> getNotificaciones(); //Requerida por CtrlUsuarios para Consultar Notificaciones
        vector<string> getSuscripciones(); //Requerida por CtrlUsuarios para Eliminar Suscripciones
        void desuscribirse(Vendedor*); //Requerida por CtrlUsuarios para Elminar Suscripciones
        void agregarCompra(Compra*); //Requerida por CtrlPromoProd para Realizar Compra
};

#include "compra.h"

#endif