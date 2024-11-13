#ifndef DATAENVIOPENDIENTE
#define DATAENVIOPENDIENTE

#include "dataFecha.h"

using namespace std;

class DataEnvioPendiente {
    private:
        string solicitud;
        string nombreCliente;
        DataFecha fecha;
    public:
        DataEnvioPendiente(string solicitud, string nombreCliente, DataFecha fecha);
        ~DataEnvioPendiente() = default;

        string getSolicitud();
        string getNombreCliente();
        DataFecha getFecha();
};

#endif