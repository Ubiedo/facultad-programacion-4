#ifndef DATACOMENTARIO
#define DATACOMENTARIO

#include "dataFecha.h"

#include <string>

using namespace std;

class DataComentario {
    private:
        string codigo, texto;
        DataFecha fecha;
    public:
        DataComentario(string codigo, int prodTotales, DataFecha fecha);
        ~DataComentario() = default;
        
        string getCodigo();
        string getTexto();
        DataFecha getFecha();
};

#endif