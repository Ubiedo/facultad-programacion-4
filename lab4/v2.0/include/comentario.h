#ifndef COMENTARIO
#define COMENTARIO

#include "usuario.h"
#include "dataFecha.h"
#include "dataComentario.h"

#include <map>
#include <vector>
#include <string>
using namespace std;

class Producto;

class Comentario {
    private:
        string texto, codigo;
        DataFecha fecha;
        Usuario* usuario;
        Producto* producto;
        Comentario* padre;
        map<string, Comentario*> respuestas;
    public:
        Comentario(string, string, DataFecha, Usuario*, Producto*, Comentario*);
        ~Comentario() = default;

        string getCodigo();
        string getTexto();
        DataFecha getFecha();
        Usuario* getUsuario();
        Producto* getProducto();
        Comentario* getPadre();
        DataComentario getDataComentario();

        void agregarRespuesta(Comentario*); //Requerida por CtrlUsuarios para Dejar Comentario
        void removerRespuesta(string); //Requerida por CtrlUsuarios para Eliminar Comentario
        vector<Comentario*> getRespuestas(); //Requerida por CtrlUsuarios para Eliminar Comentario
};

#include "producto.h"

#endif