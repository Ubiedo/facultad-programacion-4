#ifndef USUARIO
#define USUARIO

#include "dataFecha.h"
#include "dataCmtBasica.h"

#include <map>
#include <vector>
#include <string>
using namespace std;

class Comentario;

class Usuario {
    protected:
        string nickname, contrasena;
        DataFecha fechaNacimiento;
        map<string, Comentario*> comentarios;
    public:
        Usuario();
        virtual ~Usuario() = 0;
        
        string getNickname();
        string getContrasena();
        DataFecha getFechaNacimiento();
        
        void setNickname(string);
        void setContrasena(string);
        void setFechaNacimiento(DataFecha);

        void agregarComentario(Comentario*); //Requerida por CtrlUsuarios para Dejar Comentario
        void removerComentario(string); //Requerida por CtrlUsuarios para Eliminar Comentario
        bool isEmptyComentarios(); //Requerida por CtrlUsuarios para Eliminar Comentario
        Comentario* findComentario(string); //Requerida por CtrlUsuarios para Eliminar Comentario
        vector<DataCmtBasica> getComentarios(); //Requerida por CtrlUsuarios para Eliminar Comentario
};

#include "comentario.h"

#endif