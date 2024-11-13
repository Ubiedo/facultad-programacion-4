#ifndef CLIENTE
#define CLIENTE

#include "usuario.h"
#include "dataCliente.h"
#include "iObserver.h"
#include "vendedor.h"
#include "notiCliente.h"
#include "dataNotificacion.h"

#include <string>
using namespace std;

class Cliente: public Usuario, public IObserver {
    private:
        string calle, ciudad;
        int nroPuerta;
        map<string, Vendedor*> vendedores;
        set<NotiCliente*> notisCliente;
    public:
        Cliente(DataCliente);
        ~Cliente() = default;
        
        string getCalle();
        int getNroPuerta();
        string getCiudad();
        map<string, Vendedor*> getVendedores();
        set<NotiCliente*> getNotisCliente();
        
        void setCalle(string);
        void setNroPuerta(int);
        void setCiudad(string);
        //Suscripcion
        bool suscritoAVendedor(Vendedor* v);
        void suscribirAVendedor(Vendedor* v);
        set<DataNotificacion> getNotificaciones();
        void vaciarNotificaciones();
        set<string> getSuscripciones();
        void desuscribir(Vendedor* v);

        string toString();
        // IObserver
        void notificar();
};

#endif