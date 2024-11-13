#ifndef DATAENVIOPENDIENTE
#define DATAENVIOPENDIENTE

#include "dataFecha.h"

using namespace std;

class DataEnvioPendiente {
    private:
        string nombreCliente;
        DataFecha fecha;
    public:
        DataEnvioPendiente(string nombreCliente, DataFecha fecha);
        ~DataEnvioPendiente() = default;

        string getNombreCliente();
        DataFecha getFecha();
};

#endif