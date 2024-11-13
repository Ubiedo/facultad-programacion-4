#ifndef DATAUSUARIO
#define DATAUSUARIO

#include "dataFecha.h"

#include <string>
using namespace std;

class DataUsuario {
    protected:
        string nickname;
        DataFecha fechaNacimiento;
    public:
        DataUsuario();
        virtual ~DataUsuario() = 0;

        string getNickname();
        DataFecha getFechaNacimiento();
};

#endif