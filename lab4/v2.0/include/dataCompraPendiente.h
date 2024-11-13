#ifndef DATACOMPRAPENDIENTE
#define DATACOMPRAPENDIENTE

#include "dataFecha.h"

#include <string>
using namespace std;

class DataCompraPendiente {
    private:
        string codigo, nickname;
        DataFecha fecha;
    public:
        DataCompraPendiente(string, string, DataFecha);
        ~DataCompraPendiente() = default;

        string getCodigo();
        string getNickname();
        DataFecha getFecha();
};

#endif