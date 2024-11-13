#ifndef USUARIO
#define USUARIO

#include "dataFecha.h"

#include <string>
using namespace std;

class Usuario {
    protected:
        string nickname, contrasena;
        DataFecha fechaNacimiento;
    public:
        Usuario();
        virtual ~Usuario() = 0;
        
        string getNickname();
        string getContrasena();
        DataFecha getFechaNacimiento();
        
        void setNickname(string);
        void setContrasena(string);
        void setFechaNacimiento(DataFecha);
};

#endif