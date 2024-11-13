#ifndef DATACOMENTARIO
#define DATACOMENTARIO

#include <string>
using namespace std;

class DataComentario {
    private:
        string codigo, strComentario;
    public:
        DataComentario(string, string);
        ~DataComentario() = default;

        string getCodigo();
        string getStrComentario();
};

#endif