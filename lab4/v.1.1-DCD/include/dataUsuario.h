#ifndef DATAUSUARIO
#define DATAUSUARIO

#include "dataFecha.h"

#include <string>

using namespace std;

class DataUsuario {
    protected:
        string nickname, contrasena;
        DataFecha fechaNacimiento;
    public:
        DataUsuario(string nickname, string contrasena, DataFecha fechaNacimiento);
        virtual ~DataUsuario() = 0;

        string getNickname();
        string getContrasena();
        DataFecha getFechaNacimiento();
};

#endif