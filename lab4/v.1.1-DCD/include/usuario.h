#ifndef USUARIO
#define USUARIO

#include "DataFecha.h"
#include "comentario.h"

#include <string>

using namespace std;

class Usuario {
    protected:
        string nickname, contrasena;
        DataFecha fechaNacimiento;
        map<string, Comentario*> comentarios; // si ven que es mejor set o vector, cambiarlo
    public:
        // Usuario(); // comentarios a la hora de crear un usario son 0
        virtual ~Usuario() = default;
        
        string getNickname();
        string getContrasena();
        DataFecha getFechaNacimiento();
        
        void setNickname(string nickname);
        void setContrasena(string contrasena);
        void setFechaNacimiento(DataFecha fechaNacimiento);

        vector<DataComentario> getComentarios()
        void eliminarComentario(string comentarioId)
};

#endif