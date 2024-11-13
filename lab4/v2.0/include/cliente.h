#ifndef CLIENTE
#define CLIENTE

#include "usuario.h"
#include "iObserver.h"
#include "vendedor.h"
#include "notificacion.h"
#include "dataCliente.h"
#include "dataCompraExp.h"

#include <map>
#include <vector>
#include <string>
using namespace std;

class Compra;

class Cliente: public Usuario, public IObserver {
    private:
        string calle, ciudad, nroPuerta;
        vector<Notificacion*> notificaciones;
        map<string, Vendedor*> suscripciones;
        map<string, Compra*> compras;
    public:
        Cliente(string, string, DataFecha, string, string, string);
        ~Cliente(); //Cliente se encarga de la eliminación de sus comentarios, compras y notificaciones
        
        string getCalle();
        string getNroPuerta();
        string getCiudad();
        vector<DataNotificacion> getNotificaciones();
        DataCliente getDataCliente();

        void notificar(DataNotificacion); //Requerida por IObserver
        bool estaSuscrito(string); //Requerida por CtrlUsuarios para Suscribirse a Notificaciones
        void suscribirse(Vendedor*); //Requerida por CtrlUsuarios para Suscribirse a Notificaiones
        vector<string> getSuscripciones(); //Requerida por CtrlUsuarios para Eliminar Suscripciones
        void desuscribirse(Vendedor*); //Requerida por CtrlUsuarios para Elminar Suscripciones
        void agregarCompra(Compra*); //Requerida por CtrlPromoProd para Realizar Compra
        vector<DataCompraExp> getCompraExpediente(); //Requerida por CtrlPromoProd para Expediente de Usuario
};

#include "compra.h"

#endif