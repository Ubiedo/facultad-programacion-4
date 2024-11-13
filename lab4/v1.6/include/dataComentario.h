#ifndef DATACOMENTARIO
#define DATACOMENTARIO

#include "dataFecha.h"

#include <string>
using namespace std;

class DataComentario {
    private:
        string codigoProducto, codigoPadre, nickname, texto;
        DataFecha fecha;
    public:
        DataComentario(string codigoProducto, string codigoPadre, string nickname, string texto, DataFecha fecha);
        ~DataComentario() = default;

        string getCodigoProducto();
        string getCodigoPadre();
        string getNickname();
        string getTexto();
        DataFecha getFecha();
};

#endif