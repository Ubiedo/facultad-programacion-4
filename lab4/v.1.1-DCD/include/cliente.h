#ifndef CLIENTE
#define CLIENTE

#include "iObserver.h"
#include "usuario.h"
#include "dataCliente.h"
#include "vendedor.h"
#include "compra.h"
#include "notiCliente.h"
#include "dataNotificacion.h"

using namespace std;

class Cliente : public Usuario, public IObserver {
    private:
        string calle, ciudad;
        int nroPuerta;
        map<string, Vendedor*> vendedores;
        vector<NotiCliente*> notisCliente;
        vector<Compra*> compras;
    public:
        Cliente(DataCliente dc); // se crea sin vendedores y sin notificaciones y sin compras
        ~Cliente() = default;

        string getCalle();
        string getCiudad();
        int getNroPuerta();
        map<string, Vendedor*> getVendedores();
        vector<NotiCliente*> getNotisCliente();
        vector<Compra*> getCompras();

        void nuevaCompra();
        bool suscritoAVendedor(Vendedor v);
        void suscribirAVendedor(Vendedor v);
        vector<DataNotificacion> getNotificaciones();
        void vaciarNotificaciones();
        vector<string> getSuscripciones();
        void desuscribir(Vendedor v);

        void notificar();
};

#endif