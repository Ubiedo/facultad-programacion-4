#ifndef COMENTARIO
#define COMENTARIO

#include "DataFecha.h"
#include <string>

class Comentario {
    private:
        string texto, identificador;
        DataFecha fecha;
    public:
        Comentario(string texto, string identificador, DataFecha fecha);
        ~Comentario() = default;

        string getTexto();
        string getIdentificador();
        DataFecha getFecha();

        DataComentario getDataComentario();
        void borrarRespuestas();

};

#endif