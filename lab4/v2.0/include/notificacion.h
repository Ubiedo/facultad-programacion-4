#ifndef NOTIFICACION
#define NOTIFICACION

#include "dataProdBasica.h"
#include "dataNotificacion.h"

#include <vector>
#include <string>
using namespace std;

class Notificacion {
    private:
        string codigo, nicknameVendedor, nombrePromo;
        vector<DataProdBasica> productosPromo;
    public:
        Notificacion(string, string, string, vector<DataProdBasica>);
        ~Notificacion() = default;

        string getCodigo();
        string getNicknameVendedor();
        string getNombrePromo();
        vector<DataProdBasica> getProductosPromo();
        DataNotificacion getDataNotificacion();
};

#endif