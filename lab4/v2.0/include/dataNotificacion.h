#ifndef DATANOTIFICACION
#define DATANOTIFICACION

#include "dataProdBasica.h"

#include <vector>
#include <string>
using namespace std;

class DataNotificacion {
    private:
        string nicknameVendedor, nombrePromo;
        vector<DataProdBasica> productosPromo;
    public:
        DataNotificacion(string, string, vector<DataProdBasica>);
        ~DataNotificacion() = default;

        string getNicknameVendedor();
        string getNombrePromo();
        vector<DataProdBasica> getProductosPromo();
};

#endif